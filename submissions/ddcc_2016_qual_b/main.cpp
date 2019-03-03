#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int R, N, M;
double f(int n){
	if(n < 1 || n >= N) return 0;
	return R * sqrt(1 - pow((double)(N - 2 * n) / N, 2.0));
}
int main(void)
{
	cin >> R >> N >> M;
	double ans = 0;
	Rep(i, N + M - 1){
		double a = f(i + 1);
		double b = f(i + 1 - M);
		ans += (a > b) ? a : b;
	}
	printf("%.9lf", ans * 2);
	return 0;
}
