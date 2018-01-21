#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int main(void)
{
	int N, a, b;
	double L;
	cin >> N >> a >> b >> L;
	Loop(N){
		L = b * L / a;
	}
	printf("%.9f\n", L);
	return 0;
}
