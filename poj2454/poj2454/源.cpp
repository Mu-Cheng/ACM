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

struct Po {
	int v, pos;
};

Po a[60 * 3 + 200];
Po b[60 * 3 + 200];
Po c[60 * 3 + 200];

bool cmp(const Po& a, const Po& b) {
	return a.v > b.v;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	read(n);
	int i;
	f(i, 1, 3 * n) {
		read(a[i].v);
		a[i].pos = i;
	}
	sort(a + 1, a + 1 + 3 * n, cmp);
	ll sum1 = 0;
	ll sum2 = 0;
	int cnt = 1;
	for (i = 1; i <= 2 * n; i += 2) {
		sum1 += a[i].v;
		b[cnt++] = a[i];
	}
	cnt = 1;
	for (i = 2; i <= 2 * n; i += 2) {
		sum2 += a[i].v;
		c[cnt++] = a[i];
	}
	while (sum1<=n*500||sum2<=n*500) {
		int p1 = rand() % n + 1;
		int p2 = rand() % n + 1;
		if (sum1 != sum2) {
			sum1 += c[p2].v - b[p1].v;
			sum2 += b[p1].v - c[p2].v;
			Po tem = b[p1]; b[p1] = c[p2]; c[p2] = tem;
		}
	}

	f(i, 1, n)
		printf("%d\n", b[i].pos);
	f(i, 1, n)
		printf("%d\n", c[i].pos);
	f(i, 2 * n + 1, 3 * n)
		printf("%d\n", a[i].pos);














	return 0;
}