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

#define PrintLn(X) cout << X &
lt;< endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int A[100000];
int main(void)
{
	int N;
	cin >> N;

	int n[5] = {0};
	Rep(i, N){
		int a;
		cin >> a;
		n[a]++;
	}
	int ans = n[4];
	ans += n[3];
	n[1] -= n[3];
	if(n[1] < 0) n[1] = 0;
	ans += n[2] / 2;
	if(n[2] % 2 == 1){
		ans += 1;
		n[1] -= 2;
		if(n[1] < 0) n[1] = 0;
	}
	ans += (n[1] + 3) / 4;


	PrintLn(ans);
	return 0;
}
