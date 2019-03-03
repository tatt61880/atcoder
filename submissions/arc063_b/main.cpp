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
typedef long long ll;
typedef unsigned long long ull;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int A[100000];
int B[100000];
int main(void)
{
	int N, t;
	cin >> N >> t;
	t /= 2;
	Rep(i, N) cin >> A[i];
	int M = A[N - 1];
	for(int i = N - 2; i >= 0; i--){
		B[i] = M - A[i];
		if(A[i] > M){
			M = A[i];
		}
	}
	int m = B[0];
	Rep(i, N - 1){
		if(B[i] > m){
			m = B[i];
		}
	}
	int ans = 0;
	Rep(i, N - 1){
		if(m == B[i]) ans++;
	}
	PrintLn(ans);
	return 0;
}
