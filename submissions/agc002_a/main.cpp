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
	int a, b;
	cin >> a >> b;
	if(a > 0){
		PrintLn("Positive");
	}else if(a <= 0 && 0 <= b){
		PrintLn("Zero");
	}else{
		if((a - b) % 2){
			PrintLn("Positive");
		}else{
			PrintLn("Negative");
		}
	}
	return 0;
}
