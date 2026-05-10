#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const double PI = 3.14159265358979323846264338327950;
const LL MOD = 1000000007;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	int N;
	cin >> N;
	int L[200];
	Rep(i, 2*N){
		cin >> L[i];
	}
	sort(L, L+2*N);
	int ans = 0;
	Rep(i, N){
		ans += L[2 * i];
	}
	PrintLn(ans);

	return 0;
}
