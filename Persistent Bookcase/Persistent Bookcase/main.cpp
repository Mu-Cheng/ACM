//
//  main.cpp
//  Persistent Bookcase
//
//  Created by Student04 on 16/9/6.
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
    int kind;
    int x,y;
};

int n,m,q;
int father[SIZE];
int son[SIZE];
int brother[SIZE];
Po op[SIZE];
int ans[SIZE];
bitset<1010>bit[1010];

void dfs(int cur,int pSum){
    
    int so = son[cur];
    while (so!=-1) {
        if(op[so].kind==1){
            bitset<1010>tem = bit[op[so].x];
            int t;
            if (bit[op[so].x][op[so].y]) {
                t = 0;
            }else
                t = 1;
            bit[op[so].x].set(op[so].y);
            ans[so] = pSum+t;
            dfs(so, pSum+t);
            bit[op[so].x] = tem;
        }
        
        if(op[so].kind==2){
            bitset<1010>tem = bit[op[so].x];
            int t;
            if (bit[op[so].x][op[so].y]) {
                t = -1;
            }else
                t = 0;
            bit[op[so].x].reset(op[so].y);
            ans[so] = pSum+t;
            dfs(so, pSum+t);
            bit[op[so].x] = tem;
        }
        
        if(op[so].kind==3){
            bitset<1010>tem = bit[op[so].x];
            int s,t;
            bit[op[so].x].reset(0);
            s = bit[op[so].x].count();
            if (bit[op[so].x][m+1]) {
                s-=1009-m;
            }
            bit[op[so].x].flip();
            bit[op[so].x].reset(0);
            t = bit[op[so].x].count();
            if (bit[op[so].x][m+1]) {
                t-=1009-m;
            }
            ans[so] = pSum-s+t;
            dfs(so, pSum-s+t);
            bit[op[so].x] = tem;
        }
        
        if(op[so].kind==4){
            ans[so] = ans[op[so].x];
        }
        
        so = brother[so];
    }
    
    
}

int setAns(int k){
    if (ans[op[k].x]==-1) {
        return ans[op[k].x] = setAns(op[k].x);
    }else
        return ans[op[k].x];
}

int findAns(int k){
    if (op[k].kind==4) {
        return op[k].x = findAns(op[k].x);
    }else
        return k;
    
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    
    read(n);read(m);read(q);
    int i;
    int s = 0;
    m_1(brother);
    m_1(son);
    m_1(ans);
    f(i,1,q){
        int k;read(k);
        int a,b;
        op[i].kind = k;
        if (k==1) {
            read(a);read(b);
            op[i].x = a;op[i].y = b;
        }
        
        if (k==2) {
            read(a);read(b);
            op[i].x = a;op[i].y = b;
        }
        
        if (k==3) {
            read(a);
            op[i].x = a;
        }
        
        if (k==4) {
            read(a);
            int tt = findAns(a);
            s = op[i].x = tt;
            continue;
        }
        
        father[i] = s;
        brother[i] = son[father[i]];
        son[father[i]] = i;
        s = i;
        
    }
    
    ans[0] = 0;
    dfs(0,0);
    f(i,1,q)
    if (op[i].kind==4) {
        ans[i] = setAns(i);
        printf("%d\n",ans[i]);
    }else{
        printf("%d\n",ans[i]);
    }

//    cout<<"  ";
//    f(i,1,q){
//        cout<<i<<"\t";
//    }
//    cout<<endl;
//    
//    cout<<"f ";
//    f(i,1,q){
//        cout<<father[i]<<"\t";
//    }
//    cout<<endl;
//    
//    cout<<"b ";
//    f(i,1,q){
//        cout<<brother[i]<<"\t";
//    }
//    cout<<endl;
//    
//    cout<<"s ";
//    f(i,1,q){
//        cout<<son[i]<<"\t";
//    }
//    cout<<endl;
    
    return 0;
}