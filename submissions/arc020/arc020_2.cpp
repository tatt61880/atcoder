#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
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
	int n, c;
	cin >> n >> c;
	int x[11] = {0};
	int y[11] = {0};
	int a;
	Loop(n / 2){
		cin >> a;
		x[a]++;
		cin >> a;
		y[a]++;
	}
	if(n % 2){
		cin >> a;
		x[a]++;
	}
	int mx = 0;
	For(i, 1, 11){
		For(j, 1, 11){
			if(i == j) continue;
			mx = max(mx, x[i] + y[j]);
		}
	}
	PrintLn((n - mx) * c);
	return 0;
}
