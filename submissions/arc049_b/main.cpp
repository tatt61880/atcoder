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
#include <casser
t>
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
	int x[1000];
	int y[1000];
	int c[1000];
	Rep(i, N){
		cin >> x[i] >> y[i] >> c[i];
	}
	double hi = 2000 * 100000;
	double lo = 0;
	while(hi - lo > 0.0000001){
		double mi = (hi + lo) / 2;
		double x_min = -1000000;
		double x_max =  1000000;
		double y_min = -1000000;
		double y_max =  1000000;
		Rep(i, N){
			x_min = max(x_min, x[i] - mi / c[i]);
			x_max = min(x_max, x[i] + mi / c[i]);
			y_min = max(y_min, y[i] - mi / c[i]);
			y_max = min(y_max, y[i] + mi / c[i]);
		}
		if(x_min <= x_max && y_min <= y_max){
			hi = mi;
		}else{

			lo = mi;
		}
	}
	printf("%.6f\n", lo);
	return 0;
}
