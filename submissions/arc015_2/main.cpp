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
	int N;
	cin >> N;
	int a[6] = {0};
	Loop(N){
		double M, m;
		cin >> M >> m;
		a[0] += 35 <= M ? 1 : 0;
		a[1] += 30 <= M && M < 35 ? 1 : 0;
		a[2] += 25 <= M && M < 30 ? 1 : 0;
		a[3] += 25 <= m ? 1 : 0;
		a[4] += m < 0 && 0 <= M ? 1 : 0;
		a[5] += m < 0 && M < 0 ? 1 : 0;
	}
	Rep(i, 6){
		cout << a[i];
		if(i != 5){
			cout << " ";
		}else{
			cout << endl;
		}
	}
	return 0;
}
