#include <iostream>
#include <string>
#include <map>
#include <set>
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
	int N, K;
	cin >> N >> K;
	int a = 0;
	int count = 0;
	int ans = 0;
	Loop(N){
		int A;
		cin >> A;
		if(a < A){
			count++;
		}else{
			count = 1;
		}
		if(count >= K){
			ans++;
		}
		a = A;
	}
	PrintLn(ans);
	return 0;
}
