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
#define SIZE ( 200+20)
char str[SIZE];
char ans[SIZE];

int key[SIZE];
int num[SIZE];
int vis[SIZE];
int G[SIZE][SIZE];

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (scanf("%d",&n),n) {
		int i,j;
		f(i, 1, n) scanf("%d", &key[i]);

		m0(G); m0(vis); m0(num);
		int cnt = 1;
		f(i, 1, n) {
			if (!vis[i]) {
				vis[i] = 1;
				int tem = key[i];
				G[cnt][num[cnt]++] = tem;
				//tem = key[tem];
				while (!vis[tem]) {
					vis[tem] = 1;
					tem = key[tem];
                    G[cnt][num[cnt]++] = tem;
                }
				cnt++;
			}
        }
		int m;
		while (scanf("%d",&m),m) {
			gets_s(str,SIZE-5);
			int len = strlen(str);
			f(i, len, n) str[i] = ' ';
			str[n + 1] = '\0';
            f(i, 1, cnt - 1)
				f(j, 0, num[i] - 1) {
				ans[G[i][(j + m) % num[i]]] = str[G[i][j]];
                }
            ans[n+1] = '\0';
            printf("%s\n",ans+1);
		}
		printf("\n");
	}





















	return 0;
}