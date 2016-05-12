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

template<typename T> inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	x *= f;
}

double ans[10];

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int N;
	read(N);
	int CNT = 1;
	while (N--) {
		int _n, _m, _t, _c;
		read(_n); read(_m); read(_t); read(_c);
		double n = _n, m = _m, t = _t, c = _c;
		double a, b;
		if (1 == _n && 1 == _m) {
			ans[1] = 100.0;
			ans[2] = ans[3] = ans[4] = 0;
			/*printf("Case %d:\n", CNT++);
			printf("Probability of covering 1 tile  = %.4lf%%\n", 100.0000);
			printf("Probability of covering 2 tiles = %.4lf%%\n", 0.0);
			printf("Probability of covering 3 tiles = %.4lf%%\n", 0.0);
			printf("Probability of covering 4 tiles = %.4lf%%\n", 0.0);*/

			/*printf("Case %d:\n", num_case++);
			printf("Probability of covering 1 tile  = %.4lf%%\n", s[1] / s[0] * 100.0);
			printf("Probability of covering 2 tiles = %.4lf%%\n", s[2] / s[0] * 100.0);
			printf("Probability of covering 3 tiles = %.4lf%%\n", s[3] / s[0] * 100.0);
			printf("Probability of covering 4 tiles = %.4lf%%\n", s[4] / s[0] * 100.0);*/

			//continue;
		} else if (1 == _n) {
			a = 2.0*t*(t - c / 2.0) + (m - 2.0)*t*(t - c);
			b = n*t*m*t;
			double sum = 100.0;
			ans[1] = a*100.0 / b;
			sum -= a * 100.0 / b;
			ans[2] = sum;
			ans[3] = ans[4] = 0;
			//printf("Case %d:\n", CNT+/*+);
			//printf("Probability of covering 1 tile  = %.4lf%%\n", a*100.0 / b);
			//sum -= a * 100.0 / b;
			//printf("Probability of covering 2 tiles = %.4lf%%\n", sum);
			//printf("Probability of covering 3 tiles = %.4lf%%\n", 0.0);
			//printf("Probability of covering 4 tiles = %.4lf%%\n", 0.0);*/
			//continue;
		} else if (1 == _m) {
			a = 2.0*t*(t - c / 2.0) + (n - 2.0)*t*(t - c);
			b = n*t*m*t;
			double sum = 100.0;
			//printf("Case %d:\n", CNT++);
			//printf("Probability of covering 1 tile  = %.4lf%%\n", a*100.0 / b);
			ans[1] = a*100.0 / b;
			sum -= a * 100.0 / b;
			ans[2] = sum;
			ans[3] = ans[4] = 0;
			//printf("Probability of covering 2 tiles = %.4lf%%\n", sum);
			//printf("Probabkility of covering 3 tiles = %.4lf%%\n", 0.0);
			//printf("Prokbability of covering 4 tiles = %.4lf%%\n", 0.0);
			//continue;
		} else {
			a = (n - 2.0)*(m - 2.0)*(t - c)*(t - c) + 4.0*(t - c / 2.0)*(t - c / 2.0) + (2.0*(n - 2.0) + 2.0*(m - 2.0))*(t - c / 2.0)*(t - c);
			b = n*t*m*t;
			double sum = 100.0;
			ans[1] = a*100.0 / b;
			sum -= a * 100.0 / b;
			a = (2.0*(n - 1) + 2.0*(m - 1))*c*(t - c / 2.0) + ((n - 2.0)*(m - 1.0) + (n - 1.0)*(m - 2.0))*c*(t - c);
			ans[2] = a*100.0 / b;
			sum -= a * 100.0 / b;
			c /= 2.0;
			a = (n - 1)*(m - 1)*c*c*PI;
			sum -= a * 100.0 / b;
			ans[4] = a*100.0 / b;
			ans[3] = sum;
		}
		printf("Case %d:\n", CNT++);
		printf("Probability of covering 1 tile  = %.4lf%%\n", ans[1]);
		printf("Probability of covering 2 tiles = %.4lf%%\n", ans[2]);
		printf("Probability of covering 3 tiles = %.4lf%%\n", ans[3]);
		printf("Probability of covering 4 tiles = %.4lf%%\n", ans[4]);
		printf("\n");


	}





















	return 0;
}