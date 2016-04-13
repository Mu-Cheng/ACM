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
#define SIZE ( 100000+11)

struct Po {
	int x, y;
};

bool cmp(const Po& a, const Po& b) {
	if (a.x < b.x)
		return true;
	else if (a.x == b.x)
		return a.y < b.y;
	return false;
}

ll a[SIZE];
Po G[SIZE*2];
int b[SIZE*2];
int father[SIZE];
int brother[SIZE];
int son[SIZE];
ll dp[SIZE];
ll sum;

void bfs(int root) {
	m0(father); m0(brother); m0(son);
	queue<int>qu;
	qu.push(root);
	while (!qu.empty()) {
		root = qu.front(); qu.pop();
		int v = b[root];
		while (G[v].x==root) {
			if (father[root] != G[v].y) {
				father[G[v].y] = root;
				brother[G[v].y] = son[root];
				son[root] = G[v].y;
				qu.push(G[v].y);
			}
			v++;
		}
	}
}

void dfs(int root) {
	dp[root] = a[root];
	int v = son[root];
	while (v) {
		dfs(v);
		dp[root] += dp[v];
		v = brother[v];
	}
}

ll Abs(ll k) {
	if (k < 0)
		return (-1LL)*k;
	return k;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	int CNT = 1;
	while (~scanf("%d%d",&n,&m)&&(n||m) ) {
		int i, j;
		sum = 0;
		f(i, 1, n)
		{
			scanf("%I64d", &(a[i]));
			sum += a[i];
		}
		j = 0;
		f(i, 1, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			//if (x > y) { x ^= y; y ^= x; x ^= y;}
			if (x != y) {
				G[++j].x = x; G[j].y = y;
				G[++j].x = y; G[j].y = x;
			}
		}
		
		sort(G + 1, G + 1 + j, cmp);

		m0(b);
		f(i, 1, j)
			if (!b[G[i].x])
				b[G[i].x] = i;

		bfs(1);
		m0(dp);
		dfs(1);
		ll ans = 0x7ffffffffffffll;
		f(i, 1, n)
			if (Abs(dp[i] - (sum - dp[i])) < ans)
				ans = Abs(dp[i] - (sum - dp[i]));
		printf("Case %d: %I64d\n", CNT++, ans);
	}





















	return 0;
}