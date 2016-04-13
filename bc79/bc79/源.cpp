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
ll a, b, c, d;
int CNT;
ll ans,Max;
inline int cnt(ll k) {
	int sum = 0;
	while (k) {
		sum++;
		k >>= 1;
	}
	return sum;
}

void dfs(ll k) {
	ll i, j;
	ll tem = 0;
	fi(i, CNT - 1, 0) {
		if (!((1LL << i)&k)) {
			tem ^= (1LL << i);
			if (tem >= a&&tem <= b)
				;
			else
				tem ^= (1LL << i);

		}
	}
	if (tem == 0) {
		Max = a^k;
		f(i, a+1, b)
			Max = max(Max, i^k);
	} else 
		Max ^= tem;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int N;
	scanf("%d", &N);
	while (N--) {
		scanf("%I64d%I64d%I64d%I64d", &a,&b,&c,&d);
		ll i, j;
		if (b > d) {
			ll tem;
			tem = a; a = c; c = tem;
			tem = b; b = d; d = tem;
		}
		CNT = cnt(d);
		i = d;
		ans = 0;
		ll tem1 = 1LL << (CNT-1),tem2 = 0;
		fi(i, CNT - 1, 0) {
			tem1 ^= 1LL << i;
			if (tem1 >= c&&tem1 <= d&&tem2 >= a&&tem2 <= b) {
				continue;
			}
			tem1 ^= 1LL << i;
			tem2 ^= 1LL << i;
			if (tem1 >= c&&tem1 <= d&&tem2 >= a&&tem2 <= b) {
				continue;
			}
			tem2 ^= 1LL << i;
		}
		ans = tem1^tem2;
		printf("%I64d\n", ans);
	}

1
1 1000000000000000000 1 1000000000000000000




















	return 0;
}