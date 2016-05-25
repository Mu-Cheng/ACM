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
const double PI = acos(-1.0);

using namespace std;
#define SIZE ( )
const double esp = 1e-9;

template<typename T> inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	x *= f;
}

struct Po {
	double x, y;
};

Po G[1005];
int n;

double cal(double d) {
	int i, j;
	double ans = 0.0;
	f(i,1,n)
		f(j, i+1, n) {
			double t1 = fabs(cos(d)*(G[i].y - G[j].y) - sin(d)*(G[i].x - G[j].x));
			double t2 = fabs(sin(d)*(G[i].y - G[j].y) + cos(d)*(G[i].x - G[j].x));
			//ans = max(ans, max(t1, t2));
			if (ans < t1)ans = t1;
			if (ans < t2)ans = t2;
		}
	return (ans*ans);
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int N;
	read(N);
	while (N--) {
		read(n);
		int i, j;
		f(i, 1, n)
			scanf("%lf%lf", &(G[i].x), &(G[i].y));
		double ans1, ans2;
		double L = 0, R = PI;
		while (R-L>=esp) {
			double mid = (R + L) / 2.0;
			double midMid = (mid + R) / 2.0;
			ans1 = cal(mid);
			ans2 = cal(midMid);
			if (ans1 < ans2)
				R = midMid;
			else
				L = mid;
		}

		printf("%0.2lf\n", ans1<ans2?ans1:ans2);


	}




















	return 0;
}