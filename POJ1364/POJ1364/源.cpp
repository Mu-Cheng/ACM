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

template<typename T> inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	x *= f;
}

struct Edge {
	int u, v, w;
	Edge() { u = v = w = 0; }
};

struct Edge1 {
	Edge G[150000 + 10];
	int Edge_size;
	Edge1() { Edge_size = 0; };
	void push_back(int u, int v, int w) {
		G[Edge_size].u = u; G[Edge_size].v = v;
		G[Edge_size].w = w;
		Edge_size++;
	}
};

int d[30000 + 10];
Edge1 a;

int Bllman(int n) {
	mm(d); d[0] = 0;
	int i, j;
	f(i, 1, n) {
		int ok = 0;
		f(j,0,a.Edge_size-1)
			if (d[a.G[j].v] > d[a.G[j].u] + a.G[j].w) {
				ok = 1;
				d[a.G[j].v] = d[a.G[j].u] + a.G[j].w;
			}
		if (!ok) break;
	}
	if (i == n + 1)
		return 0;
	else
		return 1;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (~scanf("%d",&n)&&n) {
		scanf("%d", &m);
		int u, v, w, i;
		char s[5];
		a.Edge_size = 0;
		f(i, 1, m) {
			scanf("%d %d %s %d", &u, &v, s, &w);
			if (s[0] == 'g')
				a.push_back(u + v + 1, u, -w - 1);
			else
				a.push_back(u, u + v + 1, w - 1);
		}
		//d[i] - d[0] >= 0
		f(i, 1, n + 1)
			a.push_back(i, 0, 0);

		if (Bllman(n + 2))
			printf("lamentable kingdom\n");
		else
			printf("successful conspiracy\n");
	}

	return 0;
}