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
int d[10 + '0'] = {0};
int f(int num){
	char numStr[10];
	sprintf(numStr, "%d", num);
	int len = strlen(numStr);
	Rep(i, len){
		if(d[numStr[i]]){
			return 0;
		}
	}
	return 1;
}
int main(void)
{
	int N, K;
	cin >> N >> K;
	Rep(i, K){
		char D;
		cin >> D;
		d[D] = 1;
	}
	For(i, N, 100000){
		if(f(i)){
			PrintLn(i);
			break;
		}
	}
	return 0;
}
