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
#define SIZE ( 10000+10)

struct Edge {
	int L, R;
};

Edge a[SIZE];
int d[SIZE];

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (~scanf("%d", &n)) {
		int i;
		int Min = INF;
		int Max = -INF;
		f(i, 1, n) {
			int L, R;
			scanf("%d%d", &L, &R);
			L++; R++;
			Min = min(L - 1, Min);
			Max = max(R, Max);
			a[i].L = L - 1;
			a[i].R = R;
		}
		m0(d);
		//f(i, Min, Max) d[i] = i;
		int ok = 1;
		while (ok) {
			ok = 0;
			f(i, 1, n) {
				if (d[a[i].L] > d[a[i].R] - 2) {
					d[a[i].L] = d[a[i].R] - 2;
					ok = 1;
				}
			}

			f(i, Min, Max - 1)
				if (d[i] > d[i + 1]) {
					d[i] = d[i + 1];
					ok = 1;
				}
			
			f(i, Min, Max - 1)
				if (d[i + 1] > d[i] + 1) {
					d[i + 1] = d[i] + 1;
					ok = 1;
				}

			

			
		}
		printf("%d\n", d[Max] - d[Min]);
	}





















	return 0;
}