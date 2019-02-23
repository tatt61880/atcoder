#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
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

#define PrintLn(X) cout << X << e
ndl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	int n, m;
	cin >> n >> m;
	int d[1000];
	Rep(i, n) d[i] = i + 1;
	int now = 0;
	Rep(i, m){
		int d_;
		cin >> d_;
		Rep(j, n) if(d[j] == d_) swap(d[j], now);
	}
	Rep(i, n) PrintLn(d[i]);
	return 0;
}
