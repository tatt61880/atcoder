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
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int a[200000];
int main(void)
{
	int N;
	cin >> N;
	Rep(i, N) cin >> a[i];
	ll sum = 0;
	Rep(i, N) sum += a[i];

	ll sum2 = 0;
	ll ans = abs(sum - 2 * a[0]);
	Rep(i, N){
		sum2 += a[i];
		if(i != 0 && i != N - 1){
			ans = min(ans, abs(sum2 - (sum - sum2)));
		}
	}
	PrintLn(ans);
	return 0;
}
