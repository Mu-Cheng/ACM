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

struct Edge {
	int u, v, k;
};

struct Edge1 {
	Edge edge[100000 + 10];
	int cnt;
	void push_back(int u, int v, int k) {
		edge[cnt].u = u;
		edge[cnt].v = v;
		edge[cnt].k = k;
		cnt++;
	}
};

Edge1 G;
int d[1234];

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (~scanf("%d%d",&n,&m)) {
		char s[5];
		int i,j;
		G.cnt = 0;
		f(i, 1, m) {
			scanf("%s", s);
			if ('P' == s[0]) {
				int u, v, k;
				scanf("%d%d%d", &u, &v, &k);
				G.push_back(u, v, -k);
				G.push_back(v, u, k);
			} else {
				int u, v;
				scanf("%d%d", &u, &v);
				G.push_back(u, v, -1);
			}
		}
		m0(d);
		f(i, 1, n)
			f(j, 0, G.cnt - 1)
				d[G.edge[j].v] = min(d[G.edge[j].v], d[G.edge[j].u] + G.edge[j].k);
		int ok = 1;
		f(j, 0, G.cnt - 1)
			if (d[G.edge[j].v] > d[G.edge[j].u] + G.edge[j].k) {
				ok = 0;
				break;
			}
		if (ok) printf("Reliable\n");
		else printf("Unreliable\n");
	}





















	return 0;
}