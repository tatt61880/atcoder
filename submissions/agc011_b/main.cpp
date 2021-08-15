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
int main(void)
{
	int N;
	cin >> N;
	Rep(i, N){
		cin >> A[i];
	}
	sort(A, A+N);
	int ans = N;
	int b = -1;
	ll sum = 0;
	Rep(i, N - 1){
		sum += A[i];
		if(sum * 2 < A[i + 1]){
			b = i;
		}
	}
	if(b == -1){
		PrintLn(ans);
	}else{
		PrintLn(ans - b - 1);
	}
	return 0;
}
