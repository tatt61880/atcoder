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
#include 
<cassert>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const double PI = 3.14159265358979323846264338327950;
const LL MOD = 1000000007;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int A[100000] = {1};
int B[100000] = {0};
int main(void)
{
	int N, M;
	cin >> N >> M;
	Rep(i, M){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		B[x]--;
		B[y]++;
		if(A[x]){
			A[y] = 1;
		}
		if(B[x] < 0) A[x] = 0;
	}
	int ans = 0;
	Rep(i, N){
		if(B[i] >= 0){
			ans += A[i];
		}
	}
	PrintLn(ans);
	return 0;
}
