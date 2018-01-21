#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
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
	int N;
	cin >> N;
	LL x[100];
	LL y[100];
	int count = 0;
	Rep(i, N){
		cin >> x[i] >> y[i];
	}
	Rep(i, N){
		Rep(j, i){
			Rep(k, j){
				LL S = ((x[i] - x[k]) * (y[j] - y[k]) - (x[j] - x[k]) * (y[i] - y[k]));
				if(S != 0 && S % 2 == 0) count++;
			}
		}
	}
	PrintLn(count);
	return 0;
}
