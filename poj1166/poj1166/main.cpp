//
//  main.cpp
//  poj1166
//
//  Created by MuChen on 16/5/11.
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

int a[15];
int b[15];
int ans;
int Ans[15];
int p[1048596];
int cnt;
int Sum;

const int Move[15][15] = {{0},
    //   0,1,2,3,4,5,6,7,8,9
    {0,1,1,0,
        1,1,0,
        0,0,0},
    {0,1,1,1,
        0,0,0,
        0,0,0},
    {0,0,1,1,
        0,1,1,
        0,0,0},
    {0,1,0,0,
        1,0,0,
        1,0,0},
    {0,0,1,0,
        1,1,1,
        0,1,0},
    {0,0,0,1,
        0,0,1,
        0,0,1},
    {0,0,0,0,
        1,1,0,
        1,1,0},
    {0,0,0,0,
        0,0,0,
        1,1,1},
    {0,0,0,0,
        0,1,1,
        0,1,1},
    
};

inline bool IsTrue(int* a){
    int i;
    f(i,1,9)if(a[i])return false;
    return true;
}

inline int makeSum(int& k,const int* a){
    int i;
    int cur = 4;
    k = 0;
    f(i,1,9){
        k+=a[i]*cur;
        cur*=4;
    }
    return k;
}

void unmakeSum(int k,int* a){
    int i;
    k/=4;
    f(i,1,9){
        a[i] = k%4;
        k/=4;
    }
}

void dfs(int cur,int sum){
    int i,j;
    if(sum>=Sum)return;
    if(10==cur){
        f(j, 1, 9)b[j] = a[j];
        f(i,1,9){
            if(Ans[i]){
                f(j,1,9){
                    if(Move[i][j])
                        b[j] = ((b[j]+Ans[i])%4+4)%4;
                }
            }
        }
        if(IsTrue(b)){
            makeSum(p[++cnt], Ans);
            Sum = sum;
            ans = cnt;
        }
        return;
    }
    
    f(i,0,3){
        Ans[cur] = i;
        dfs(cur+1,sum+i);
    }
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int i;
    f(i, 1, 9)
    read(a[i]);
    Sum = INF;
    cnt = 0;
    dfs(1,0);
    unmakeSum(p[ans], Ans);
    f(i, 1, 9)
    if(Ans[i]){
        printf("%d",i);
        Ans[i]--;
        break;
    }
    
    f(i, 1, 9)
    while(Ans[i]){
        printf(" %d",i);
        Ans[i]--;
    }
    
    printf("\n");
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
