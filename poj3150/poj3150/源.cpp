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
#define SIZE (500+10 )

template<typename T> inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	x *= f;
}

ll B[505];
ll ans[505];
ll tem[505];

ll a[SIZE];
int c[SIZE];
int n, m, d, k;

void mul(ll* a,ll* b) {
	int i, j;
	f(i, 1, n) {
		int sum = 0;
		f(j, 1, n) {
			int k = (i - j + 1) % n;
			k = (k + n) % n;
			if (k == 0)k = n;
			sum += a[j] * b[k]%m;
			sum %= m;
		}
		tem[i] = sum;
	}
	f(i, 1, n) a[i] = tem[i];
}

void fast_pow(ll k) {
	m0(ans);
	ans[1] = 1;
	while (k) {
		if (k & 1) mul(ans,B);
		mul(B,B);
		k >>= 1;
	}
}

void init() {
	m0(B);
	B[1] = 1;
	int i;
	f(i, 1, d) B[1 + i] = B[n - i + 1] = 1;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	while (~scanf("%d%d%d%d",&n,&m,&d,&k)) {
		int i;
		f(i, 1, n)read(a[i]);
		//Matrix ans(n);8
		init();
		fast_pow(k);
		mul(a, ans);
		
		printf("%I64d", a[1]);
		f(i, 2, n)
			printf(" %I64d", a[i]);
		printf("\n");
	}

	return 0;
}