#include <iostream>
#include <cstdio>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;
	printf("%.9lf", (double)C * B / A);
	return 0;
}
