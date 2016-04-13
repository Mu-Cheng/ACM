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

ll one_gcd(ll a,ll b,ll& c,ll& d) {
	if (a%b == 0) {
		c = 1; d = 0;
		return b;
	}
	ll k = one_gcd(b, a%b,c,d);
	ll tem = d;d = c;c = tem - c*(a / b);
	return k;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	ll x, y, m, n, l;
	scanf("%I64d%I64d%I64d%I64d%I64d", &x, &y, &m, &n, &l);
	ll a = m - n, b = y - x, c, d;
	if (a < 0) {
		while (a < 0) {
			a += l;
		}
		a%=l;
	}
	if (b < 0) {
		while (b < 0) {
			b += l;
		}
		b%=l;
	}
	ll k = one_gcd(a, l, c, d);
	if (k < 0)k *= -1;
	if (b%k)
		printf("Impossible\n");
	else {
		
		a /= k; l /= k; b /= k;
		k = one_gcd(a, l, c, d);
		if (k != c*a + d*l)
			c = d;
		ll ans = (b*c)%l;
		if (ans < 0)
			ans = (ans + l) % l;
		
		printf("%I64d\n", ans);
	}


















	return 0;
}