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
int T[100000];
int main(void)
{
	int N, C, K;
	cin >> N >> C >> K;
	Rep(i, N){
		cin >> T[i];
	}
	sort(T, T+N);
	int t = T[0];
	int I = 0;
	int ans = 1;
	Rep(i, N){
		if(i == I + C){
			I = i;
			t = T[i];
			ans++;
		}else if(T[i] > t + K){
			I = i;
			t = T[i];
			ans++;
		}
	}
	PrintLn(ans);
	return 0;
}
