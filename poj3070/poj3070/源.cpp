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
const int M = 10000;

template<typename T> inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	x *= f;
}

struct Matrix {
	int matrix[3][3];
	Matrix() {
		matrix[1][1] = matrix[2][1] = matrix[1][2] = 1;
		matrix[2][2] = 0;
	}
	Matrix(int k) {
		matrix[1][1] = matrix[2][2] = k;
		matrix[1][2] = matrix[2][1] = 0;

	}
	Matrix& operator * (const Matrix& a) {
		Matrix t;
		t.matrix[1][1] = (matrix[1][1] * a.matrix[1][1] % M + matrix[1][2] * a.matrix[2][1] % M) % M;
		t.matrix[1][2] = (matrix[1][1] * a.matrix[1][2] % M + matrix[1][2] * a.matrix[2][2] % M) % M;
		t.matrix[2][1] = (matrix[2][1] * a.matrix[1][1] % M + matrix[2][2] * a.matrix[2][1] % M) % M;
		t.matrix[2][2] = (matrix[2][1] * a.matrix[1][2] % M + matrix[2][2] * a.matrix[2][2] % M) % M;
		return t;
	}
};

Matrix& matrixPow(ll n) {
	Matrix a;
	Matrix ans(1);
	while (n) {
		if (n & 1)ans = ans*a;
		a = a*a;
		n >>= 1;
	}
	return ans;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	ll n;
	while (1) {
		read(n);
		if (-1 == n) break;
		Matrix ans = matrixPow(n);
		printf("%d\n", ans.matrix[1][2]);
	}





















	return 0;
}