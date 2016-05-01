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

#define LEN 500
#define MOD 10000

//定义了+ - * / % = == != >> << < > <= >= += -= *= /= %= print length pow等操作
struct INT {
	int num[LEN], len;
	bool sign;
	inline INT(long long x = 0) {
		*this = x;
	}
	inline INT(const string &str) {
		*this = str;
	}
	inline INT(const int a[], int b, bool c) {
		memcpy(num, a, sizeof num);
		len = b; sign = c;
	}
	inline INT &operator =(const string &str) {
		int start = 0;
		len = 0; sign = false;
		memset(num, 0, sizeof num);
		if (str[0] == '-') sign = true, start = 1;
		while (str[start] == '0') start++;
		for (int i = str.length() - 1; i >= start; i -= 4, len++)
			for (int j = max(start, i - 3); j <= i; j++)
				num[len] = (num[len] << 3) + (num[len] << 1) + str[j] - '0';
		if (!len) sign = false;
		if (len) len--;
		return *this;
	}
	inline INT &operator =(long long x) {
		len = 0; sign = false;
		memset(num, 0, sizeof num);
		if (x < 0) sign = true, x = -x;
		while (x)
			num[len++] = x % MOD,
			x /= MOD;
		if (len) len--;
		return *this;
	}
	inline int length() const {
		int re = len << 2, t = num[len];
		while (t) t /= 10, re++;
		return re;
	}
	inline void print() {
		if (sign) putchar('-');
		printf("%d", num[len]);
		for (int i = len - 1; i >= 0; i--)
			printf("%04d", num[i]);
	}
	inline friend void print_to_string(const INT &x, string &y) {
		stringstream stream;
		stream << x;
		stream >> y;
	}
	inline friend INT pow(const INT &x, int y) {
		INT re = 1, _x = x;
		while (y) {
			if (y & 1)
				re *= _x;
			y >>= 1;
			_x *= _x;
		}
		return re;
	}
	inline friend INT pow(const INT &x, const INT &y) {
		INT re = 1, _x = x, _y = y;
		while (_y != 0) {
			if (_y.num[0] & 1)
				re *= _x;
			_y = shr(_y);
			_x *= _x;
		}
		return re;
	}
	inline friend istream &operator >> (istream &in, INT &x) {
		string str;
		in >> str;
		x = str;
		return in;
	}
	inline friend ostream &operator <<(ostream &out, const INT &x) {
		if (x.sign) out << '-';
		out << x.num[x.len];
		for (int i = x.len - 1; i >= 0; i--)
			out.fill('0'), out.width(4), out << x.num[i];
		return out;
	}
	inline INT operator -() const {
		return INT(num, len, !sign);
	}
	inline friend INT abs(const INT &x) {
		return INT(x.num, x.len, false);
	}
	inline friend bool operator <(const INT &x, const INT &y) {
		if (x.sign ^ y.sign) return x.sign;
		int lx = x.length(), ly = y.length();
		if (lx == ly) {
			for (int i = x.len; i >= 0; i--)
				if (x.num[i] != y.num[i])
					return (x.num[i] < y.num[i]) ^ x.sign;
			return false;
		}
		return (lx < ly) ^ x.sign;
	}
	inline friend bool operator >(const INT &x, const INT &y) { return y < x; }
	inline friend bool operator <=(const INT &x, const INT &y) { return !(y < x); }
	inline friend bool operator >=(const INT &x, const INT &y) { return !(x < y); }
	inline friend bool operator ==(const INT &x, const INT &y) { return !(x < y || y < x); }
	inline friend bool operator !=(const INT &x, const INT &y) { return !(x == y); }

	inline friend INT operator +(const INT &x, const INT &y) {
		if (x.sign ^ y.sign)
			return x - (-y);
		INT re;
		re.sign = x.sign;
		re.len = max(x.len, y.len);
		for (int i = 0; i <= re.len; i++) {
			re.num[i] += x.num[i] + y.num[i];
			re.num[i + 1] = re.num[i] / MOD;
			re.num[i] %= MOD;
		}
		if (re.num[re.len + 1]) re.len++;
		return re;
	}
	inline friend INT operator -(const INT &x, const INT &y) {
		if (x.sign ^ y.sign)
			return x + (-y);
		INT re, _x = x, _y = y;
		re.sign = _x < _y;
		if (re.sign ^ _x.sign)
			swap(_x, _y);
		for (int i = 0; i <= _x.len; i++) {
			re.num[i] += _x.num[i] - _y.num[i];
			if (re.num[i] < 0)
				re.num[i] += MOD,
				re.num[i + 1]--;
		}
		re.len = _x.len;
		while (!re.num[re.len] && re.len >= 0) re.len--;
		return re;
	}
	inline friend INT operator *(const INT &x, const INT &y) {
		INT re, _x = x, _y = y;
		while (_y != 0) {
			if (_y.num[0] & 1)
				re += _x;
			_y = shr(_y);
			_x += _x;
		}
		if (y.sign) re.sign ^= 1;
		return re;
	}
	inline friend INT operator /(const INT &x, const INT &y) {
		if ((!y.len && !y.num[0]) || (!x.len && !x.num[0]) || abs(x) < abs(y)) { return INT(); }
		INT re, left, _y = abs(y);
		re.sign = x.sign ^ y.sign;
		re.len = x.len - y.len + 1;
		left.len = -1;
		for (int i = x.len; i >= 0; i--) {
			memmove(left.num + 1, left.num, sizeof(left.num) - sizeof(int));
			left.len++;
			left.num[0] = x.num[i];
			int l = 0, r = MOD - 1, mid;
			if (left < y) r = 1;
			while (l < r) {
				mid = (l + r) >> 1;
				INT t = mid;
				if (t * _y <= left)
					l = mid + 1;
				else r = mid;
			}
			re.num[i] = r - 1;
			INT t = r - 1;
			left = left - (t * _y);
		}
		while (re.num[re.len] == 0 && re.len) re.len--;
		return re;
	}
	inline friend INT operator %(const INT &x, const INT &y) {
		if ((!y.len && !y.num[0]) || (!x.len && !x.num[0])) { return INT(); }
		INT left, _y = abs(y);
		left.sign = (x.sign && !y.sign);
		left.len = -1;
		for (int i = x.len; i >= 0; i--) {
			memmove(left.num + 1, left.num, sizeof(left.num) - sizeof(int));
			left.len++;
			left.num[0] = x.num[i];
			int l = 0, r = MOD - 1, mid;
			while (l < r) {
				mid = (l + r) >> 1;
				INT t = mid;
				if (t * _y <= left)
					l = mid + 1;
				else r = mid;
			}
			INT t = r - 1;
			left = left - (t * _y);
		}
		return left;
	}
	inline friend INT shr(const INT &x) {
		INT re;
		re.len = x.len;
		for (int i = re.len; i >= 0; i--) {
			if (x.num[i] & 1 && i - 1 >= 0)
				re.num[i - 1] += MOD >> 1;
			re.num[i] += x.num[i] >> 1;
		}
		if (re.len && !re.num[re.len]) re.len--;
		return re;
	}
	INT &operator +=(const INT &x) { return *this = *this + x; }
	INT &operator -=(const INT &x) { return *this = *this - x; }
	INT &operator *=(const INT &x) { return *this = *this * x; }
	INT &operator /=(const INT &x) { return *this = *this / x; }
	INT &operator %=(const INT &x) { return *this = *this % x; }
};

template<typename T> inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	x *= f;
}

int cnt;
int List_size[20];
int List[20][300000];
//int p;
//unsigned long long SUM;
ll SUM;

void Cnt(ll n) {
	cnt = 0;
	int sum = 0;
	while (n) {
		n /= 10LL; 
		cnt++;
	}
}

bool Sum(int p,const ll& n) {
	SUM = 0;
	int i = cnt-1;
	while (i>=0) {
		if (p & (1LL<<i))
			SUM = SUM * 10LL + 7LL;
		else
			SUM = SUM * 10LL + 4LL;
		i--;
	}
	return SUM >= n;
}

void init(int cnt) {
	cnt <<= 1;
	int i,j = 0,k = 0;
	i = 0;
	i |= (1LL << (cnt / 2));
	f(i, i - 1, (1LL << cnt) - 1) {
		int sum = 0;
		f(j, 0, cnt - 1) {
			if (i&(1LL << j))
				sum++;
		}
		if (sum * 2 == cnt) {
			List[cnt/2][k++] = i;
		}
	}
	List_size[cnt/2] = k;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int N;
	int i, j;
	f(i, 1, 10)
		init(i);
	read(N);
	while (N--) {
		long long n;
		read(n);
		if (!n)n++;
		cnt = 0;
		Cnt(n);
		if (cnt % 2)cnt++;
		if (n >= 777777777444444444) {
			printf("44444444447777777777\n");
			continue;
		}
		
		int i, j;
		int ok = 0;
		i = 0;
		i |= (1LL << cnt);
		i--;
		i ^= (1LL << (cnt / 2)) - 1;
		if (!Sum(i, n))cnt += 2;
		int L = 0, R = List_size[cnt/2] - 1;
		while (L<=R) {
			int m = (L + R) >> 1;
			Sum(List[cnt/2][m], n);
			if (SUM < n)
				L = m + 1;
			else
				R = m - 1;
		}
		if(R>=0&&Sum(List[cnt/2][R], n))
			printf("%I64d",SUM);
		else {
			Sum(List[cnt/2][L], n);
			printf("%I64d", SUM);
		}
		printf("\n");
		
	}

	return 0;
}