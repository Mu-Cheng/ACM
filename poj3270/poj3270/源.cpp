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
#define SIZE (10000+10)

struct Po
{
	int k1, k2;
};

Po a[SIZE];
Po b[SIZE];
int p[SIZE];

inline bool cmp(const Po& a, const Po& b) {
	return a.k1 < b.k1;
}

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (~scanf("%d",&n)) {
		int i;
		int Min = INF;
		f(i, 1, n) {
			scanf("%d", &(b[i].k1));
			Min = min(Min, b[i].k1);
			a[i].k1 = b[i].k1;
			b[i].k2 = a[i].k2 = i;
		}

		sort(a + 1, a + 1 + n, cmp);

		m0(p);
		ll ans = 0;
		int tem;
		f(i, 1, n) {
			if (!p[i]) {
				ll sum = 0;
				ll MIN = INF;
				tem = i;
				p[tem] = 1;
				sum += b[tem].k1;
				MIN = min(MIN, (ll)b[tem].k1);
				tem = a[tem].k2;

				int cnt = 1;
				while (tem!=i) {
					p[tem] = 1;
					sum += b[tem].k1;
					MIN = min(MIN, (ll)b[tem].k1);
					tem = a[tem].k2;
					cnt++;
				}
				ans += min((sum - MIN) + (cnt - 1)*MIN, Min + MIN + sum + cnt*Min);
			}
		}
		printf("%I64d\n", ans);
	}





















	return 0;
}