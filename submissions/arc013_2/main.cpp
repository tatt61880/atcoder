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
	int N, a, b, c;
	int A = 0, B = 0, C = 0;
	cin >> N;
	Loop(N){
		cin >> a >> b >> c;
		if(a < b) swap(a, b);
		if(a < c) swap(a, c);
		if(b < c) swap(b, c);
		A = max(a, A);
		B = max(b, B);
		C = max(c, C);
	}
	PrintLn(A * B * C);
	return 0;
}
