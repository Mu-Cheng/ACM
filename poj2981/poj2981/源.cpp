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
#define SIZE (5000000+10 )

ll a[SIZE];
ll r[SIZE];

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b,a%b) ;
}

ll one_gcd(ll a, ll b, ll& c, ll& d) {
	if (a%b == 0) {
		c = 1; d = 0;
		return b;
	}
	ll k = one_gcd(b, a%b, c, d);
	ll tem = d; d = c; c = tem - c*(a / b);
	return k;
}

ll one_solve(ll a,ll b,ll l) {
	ll c, d;
	ll k = one_gcd(a, l, c, d);
	if (k != c*a + d*l) {
		c = d;
	}
	ll ans = (b*c) % l;
	if (ans < 0)
		ans = (ans + l) % l;
	return ans;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (~scanf("%d",&n)) {
		int i,j;
		ll M = 1;
		f(i, 1, n) {
			scanf("%I64d%I64d", &a[i], &r[i]);
			M *= a[i];
		}

		/*if (1 == n) {
			printf("%I64d\n")
		}*/

		int ok = 1;
		f(i, 1, n) {
			f(j, i + 1, n)
				if (1 != gcd(a[i], a[j])) {
					ok = 0;
					break;
				}
			if (!ok)break;
		}
		if (!ok) printf("-1\n");
		else {
			ll ans = 0;
			f(i, 1, n) {
				ll tem = M / a[i];
				ll k = one_solve(tem, 1, a[i]);
				ans = (ans + r[i] * tem*k%M) % M;
			}
			printf("%I64d\n", ans);
		}
	}





















	return 0;
}