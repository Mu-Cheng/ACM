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
#define f(i,a,b) for(i = (a);i<=(b);i++)
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

struct Edge {
	int y, v;
	int next;
	Edge() { y = v = next = 0; }
};

int head[30000 + 10];

struct Edge1 {
	Edge G[150000 + 10];
	int cnt;
	Edge1() { cnt = 0; };
	void push_back(int x, int y, int v) {
		G[cnt].y = y; G[cnt].v = v;
		G[cnt].next = head[x];
		head[x] = cnt++;
	}
};

int d[30000 + 10];
Edge1 a;

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m ;
	while (~scanf("%d%d",&n,&m)) {
		int i,j;
		
		m_1(head);
		a.cnt = 0;

		f(i, 1, m) {
			int x, y, v;
			read(x); read(y); read(v);
			//scanf("%d%d%d", &(x), &(y), &(v));
			a.push_back(x, y, v);
		}
		mm(d);
		d[1] = 0;

		stack<int>qu;
		qu.push(1);
		while (!qu.empty()) {
			int s = qu.top(); qu.pop();
			for(i = head[s];i != -1;i = a.G[i].next)
				if (d[a.G[i].y] > d[s] + a.G[i].v) {
					d[a.G[i].y] = d[s] + a.G[i].v;
					qu.push(a.G[i].y);
				}
		}
		printf("%d\n", d[n] - d[1]);
	}





















	return 0;
}