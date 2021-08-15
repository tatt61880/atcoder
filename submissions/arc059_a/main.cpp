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
	int a[1000];
	Rep(i, N){
		cin >> a[i];
	}

	int min = 1000000;
	For(j, -100, 101){
		int sum = 0;
		Rep(i, N){
			sum += (a[i] - j) * (a[i] - j);
		}
		if(sum < min){
			min = sum;
		}
	}
	PrintLn(min);
	return 0;
}
