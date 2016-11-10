//============================================================================
// Name        : HDU5543.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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
#define SIZE (1000+10 )

template<typename T> inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	x *= f;
}

ll a[SIZE];
ll b[SIZE];
ll dp[4444][3];

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int N;
	scanf("%d",&N);
	int CNT = 1;
	while(N--){
		int n,L;
		scanf("%d%d",&n,&L);
		L*=2;
		int i,j,k;
		ll ans = -INF;
		f(i,1,n){
			scanf("%lld%lld",&a[i],&b[i]);
			ans = max(ans,b[i]);
			a[i]*=2;
		}
		m0(dp);
		f(i,1,n){
			fi(j,L,a[i]/2)
				f(k,0,2){
					if(j>=a[i])
						dp[j][k] = max(dp[j][k],dp[j-a[i]][k]+b[i]);
					if(k>0)
						dp[j][k] = max(dp[j][k],dp[j-a[i]/2][k-1]+b[i]);
					ans = max(ans,dp[j][k]);
				}
		}
		printf("Case #%d: %lld\n",CNT++,ans);

	}













	return 0;
}
