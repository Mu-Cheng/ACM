//
//  main.cpp
//  CF 368E
//
//  Created by Student04 on 16/9/7.
//  Copyright © 2016年 MuChen. All rights reserved.
//

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
#include <bitset>
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
#define SIZE ( 100000+10)

template<typename T> inline void read(T &x) {
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
    x *= f;
}

struct Po{
    int x,y;
    ll w;
    Po (): x(0),y(0),w(0){}
    Po (int _x,int _y,const ll& _w): x(_x),y(_y),w(_w){}
};

//ll a[2010][2010];
ll sum[2010][2010];
vector<Po>ve[2010];
int p[2010];
int pp[2010];
//ll ans[1000000+10];


int n,m,k;

void b_add(int a,int b,ll c){
    int i,j;
    for(i = a;i<=n;i+=lowbit(i))
        for(j = b;j<=m;j+=lowbit(j))
            sum[i][j]+=c;
}

ll b_sum(int a,int b){
    int i,j;
    ll ans = 0;
    for(i = a;i;i-=lowbit(i))
        for(j = b;j;j-=lowbit(j))
            ans+=sum[i][j];
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
//    int n,m,k;
    read(n);read(m);read(k);
//    scanf("%d%d%d",&n,&m,&k);
    int i;
    m0(sum);
    int t;
    f(i, 1, k){
//        scanf("%d",&t);
        read(t);
        while (t--) {
            int a,b;
            ll c;
            read(a);read(b);read(c);
//            scanf("%d%d%lld",&a,&b,&c);
            ve[i].push_back(Po(a,b,c));
            b_add(a, b, c);
        }
    }
    m0(p);
    read(t);
//    scanf("%d",&t);
    char s[10];
    while (t--) {
        scanf("%s",s);
        if (s[0] == 'A') {
            int x1,y1,x2,y2;
            read(x1);read(y1);read(x2);read(y2);
//            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            f(i, 1, k){
                if (p[i]==pp[i]) {
                    continue;
                }
                
                if (!p[i]) {
                    //变为1
                    for (auto obj : ve[i]) {
                        b_add(obj.x, obj.y, obj.w);
                    }
                }else{
                    for (auto obj : ve[i]) {
                        b_add(obj.x, obj.y, -obj.w);
                    }
                }
                
                pp[i] = p[i];
                
            }
            
            
            ll ans = b_sum(x2, y2) - b_sum(x2, y1-1) - b_sum(x1-1, y2) + b_sum(x1-1,y1-1);
            printf("%lld\n",ans);
        }else{
            int pos;
            read(pos);
//            scanf("%d",&pos);
//            if (!p[pos]) {
//                //变为0
//                for (auto obj : ve[pos]) {
//                    b_add(obj.x, obj.y, -obj.w);
//                }
//            }else{
//                for (auto obj : ve[pos]) {
//                    b_add(obj.x, obj.y, obj.w);
//                }
//            }
            p[pos]^=1;
        }
    }
    
    
    
    
    
    return 0;
}
