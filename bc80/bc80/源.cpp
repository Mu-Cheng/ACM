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

#define LEN 500
#define MOD 10000

#define SIZE ( )

char s[100];
ll p;
ll mul(ll a, ll b) {
	ll ret = 0;
	for (; b; b >>= 1, a = (a + a) % p)
		if (b & 1) ret = (ret + a) % p;
	return ret;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);

	int T;
	scanf("%d", &T);
	int i;
	while (T--) {
		ll q;
		scanf("%I64d%I64d", &q, &p);
		
		if (q < 3)
			printf("0\n");
		else {
			ll a = q - 2, b = q - 1;
			if (a % 2 == 0)
				a /= 2;
			else 
				b /= 2;
			printf("%I64d\n",mul(a,b));
		}
	}




















	return 0;
}