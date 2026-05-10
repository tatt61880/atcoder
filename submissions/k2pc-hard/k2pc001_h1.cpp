#include <iostream>
#include <cmath>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (n); i++)
typedef long long LL;

typedef struct{
	LL x;
	LL y;
} Point;

Point f(int n)
{
	LL x, y;
	LL sum = (sqrt(8*(n - 1) + 1) - 1) / 2 + 2;
	y = n - (sum - 1) * (sum - 2) / 2;
	x = sum - y;
	return {x, y};
}

int main(void)
{
	int i, j;
	cin >> i >> j;
	Point pi = f(i);
	Point pj = f(j);
	LL x = pi.x + pj.x;
	LL y = pi.y + pj.y;
	LL sum = x + y;
	PrintLn((sum - 1) * (sum - 2) / 2 + y);
	return 0;
}
