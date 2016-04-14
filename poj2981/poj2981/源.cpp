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

ll m[SIZE];
ll r[SIZE];

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b,a%b) ;
}

void Exgcd(ll a, ll b, ll& d, ll& x, ll& y) {
	if (!b) {
		d = a;x = 1;y = 0;
	} else {
		Exgcd(b, a%b, d, y, x);
		y -= x*(a / b);
	}
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (~scanf("%d",&n)) {
		ll i,j;
		ll M = 1;
		f(i, 1, n) {
			scanf("%I64d%I64d", &m[i], &r[i]);
		}
		ll a = m[1], b = r[1];
		int ok = 1;
		f(i, 2, n) {
			ll k1, k2;
			ll p = gcd(a, m[i]);
			if ((r[i] - b)%p) {
				ok = 0;
				break;
			}
			ll d;
			Exgcd(a, m[i], d, k1, k2);
			k1 = (r[i] - b) / p*k1%(m[i]/p);
			k2 = (r[i] - b) / p*k2%(a/p);
			b += k1*a;
			a = a*(m[i]) / p;
			b%=a;
		}
		ll ans;
		if (ok) {
			ans = b;
			if (ans < 0) {
				ans += a;
			}
			printf("%I64d\n", ans);
		} else
			printf("-1\n");


		
	}
	



















	return 0;
}