#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <string>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <sstream>
#include <vector>
#include <iomanip>
#define m0(a) memset(a,0,sizeof(a))
#define mm(a) memset(a,0x3f,sizeof(a))
#define m_1(a) memset(a,-1,sizeof(a))
#define f(i,a,b) for(i = a;i<=b;i++)
#define fi(i,a,b) for(i = a;i>=b;i--)
#define lowbit(a) ((a)&(-a))
#define FFR freopen("data.in","r",stdin)
#define FFW freopen("data.out","w",stdout)
#define INF 0x3f3f3f3f
typedef long long ll;
typedef long double ld;
const ld PI = acos(-1.0);

using namespace std;
#define SIZE ( )

map<string, int>ma;

int a[400][400];
int ans[400];
int N, M;

int extend_gcd(int A, int B, int &x, int &y) {
	if (B == 0) {
		x = 1, y = 0;
		return A;
	} else {
		int r = extend_gcd(B, A%B, x, y);
		int t = x;
		x = y;
		y = t - A / B*y;
		return r;
	}
}

int lcm(int A, int B) {
	int x = 0, y = 0;
	return A*B / extend_gcd(A, B, x, y);
}

void Guass() {
	int i, j, row, col;
	for (row = 1, col = 1; row <= M && col <= N; row++, col++) {
		for (i = row; i <= M; i++)
			if (a[i][col]) break;
		if (i == M + 1) {
			row--;
			continue;
		}
		if (i != row)
			for (j = 1; j <= N + 1; j++) swap(a[row][j], a[i][j]);
		for (i = row + 1; i <= M; i++) {
			if (a[i][col]) {
				int LCM = lcm(a[row][col], a[i][col]);//利用最小公倍数去化上三角
				int ch1 = LCM / a[row][col], ch2 = LCM / a[i][col];
				for (j = col; j <= M; j++)
					a[i][j] = ((a[i][j] * ch2 - a[row][j] * ch1) % 7 + 7) % 7;
			}

		}

	}

	for (i = row; i <= M; i++)//无解
	{
		if (a[i][N + 1] != 0) {
			printf("Inconsistent data.\n");
			return;
		}
	}
	if (row < N + 1)//无穷多解
	{
		printf("Multiple solutions.\n");
		return;
	}
	//唯一解时
	for (i = N; i >= 1; i--) {
		int ch = 0;
		for (j = i + 1; j <= N; j++) {
			ch = (ch + ans[j] * a[i][j] % 7) % 7;
		}
		int last = ((a[i][N + 1] - ch) % 7 + 7) % 7;
		int x = 0, y = 0;
		int d = extend_gcd(a[i][i], 7, x, y);
		x %= 7;
		if (x < 0) x += 7;
		ans[i] = last*x / d % 7;
		if (ans[i] < 3) ans[i] += 7;
	}
	for (int i = 1; i <= N; i++) {
		if (i == 1)
			printf("%d", ans[i]);
		else
			printf(" %d", ans[i]);

	}
	printf("\n");
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	//`MON', `TUE', `WED', `THU', `FRI', `SAT' and `SUN'.
	ma["MON"] = 1; ma["TUE"] = 2;
	ma["WED"] = 3; ma["THU"] = 4;
	ma["FRI"] = 5; ma["SAT"] = 6;
	ma["SUN"] = 7;

	while (~scanf("%d%d", &N, &M) && (N || M)) {
		int k;
		char s[5], e[5];
		int i, j;
		m0(a);
		m0(ans);
		f(i, 1, M) {
			scanf("%d %s %s", &k, s, e);
			f(j, 1, k) {
				int b;
				scanf("%d", &b);
				a[i][b]++;
				a[i][b] %= 7;
			}
			a[i][N + 1] = ((ma[e] - ma[s] + 1) % 7 + 7) % 7;
		}
		Guass();

	}


















	return 0;
}