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

template<typename T> inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	x *= f;
}

double P[(1 << 8) + 10][(1 << 8) + 10];
double dp[10][(1 << 8) + 10];

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (1) {
		read(n);
		if (-1 == n)break;
		int i, j, k;
		f(i, 1, 1 << n)
			f(j, 1, 1 << n)
				scanf("%lf", &P[i][j]);
		m0(dp);
		f(i, 1, 1 << n) {
			if (i & 1)dp[1][i] = P[i][i + 1];
			else dp[1][i] = P[i][i - 1];
		}
		
		f(i, 2, n) {
			f(j, 1, 1 << n) {
				//一定注意位运算优先级！！！！！！
				int p1 = (j + (1 << (i - 1)) - 1) / (1 << (i - 1));
				if (p1 & 1)
					f(k, p1*(1 << (i - 1)) + 1, (p1 + 1)*(1 << (i - 1)))
						dp[i][j] += dp[i - 1][j] * dp[i - 1][k] * P[j][k];
				else
					f(k, (p1 - 2)*(1 << (i - 1)) + 1, (p1 - 1)*(1 << (i - 1)))
						dp[i][j] += dp[i - 1][j] * dp[i - 1][k] * P[j][k];
			}
		}
		double Mv = dp[n][1];
		int ans = 1;
		f(i, 2, 1 << n) {
			if (dp[n][i] > Mv) {
				Mv = dp[n][i];
				ans = i;
			}
		}
		printf("%d\n", ans);
	}





















	return 0;
}