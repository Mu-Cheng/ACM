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

ll gcd(ll a, ll b) {
	if (!b) {
		return a;
	} else {
		gcd(b, a%b);
	}
}

ll mod_pow(ll x, ll n) {
	ll res = 1;
	while (n>0) {
		if (n & 1) res = res*x;
		x = x*x;
		n >>= 1;
	}
	return res;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (~scanf("%d",&n)&&n!=-1) {
		if (!n) {
			printf("0\n");
			continue;
		}
		ll ans = 0;
		int i;
		f(i, 1, n)
			ans += mod_pow(3, gcd(n, i));
		ans /= n;
		ll tem = mod_pow(3, (n + 1) >> 1);
		if (n & 1)
			printf("%I64d\n", (ans + tem) >> 1);
		else
			printf("%I64d\n", ((tem * 4 / 2) + ans)>>1);

	}





















	return 0;
}