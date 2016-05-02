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

int G[10];
int a[70];
int p[10];

void init() {
	int i;
	f(i, 0, (1 << 6) - 1)
		a[i] = (i << 1) ^ (i >> 1)^i;
}

bool dfs(int cur,int pre,int now) {
	if (cur == 6) {
		return (pre & 63) == 0;
	}
	p[cur] = pre;
	if(dfs(cur + 1, (now^a[p[cur]])&63, (p[cur] ^ G[cur + 1])& 63))
		return true;
	
	return false;
}


int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	//FFR;
	int N;
	int CNT = 1;
	init();
	read(N);
	while (N--) {
		int i, j;
		f(i, 1, 5) {
			int x;
			int tem = 0;
			f(j, 1, 6) {
				read(x);
				tem = (tem << 1) | x;
			}
			G[i] = tem;
		}
		m0(p);
		f(i, 0, (1 << 6) - 1) {
			p[1] = i;
			if (dfs(2, (a[i]^G[1])&63, (i^G[2])&63)) {
				break;
			}
		}
		printf("PUZZLE #%d\n",CNT++);
		f(i, 1, 5) {
			if ((1 << 5)&p[i])
				printf("1");
			else
				printf("0");
			fi(j, 4, 0)
				if ((1 << j)&p[i])
					printf(" 1");
				else
					printf(" 0");

			printf("\n");

		}
	}

	return 0;
}