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
#
include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

double P;
double f(double x){
	return x + P / pow(2, x / 1.5);
}

int main(void)
{
	cin >> P;
	double LL = 0;
	double MM = P / 2;
	double HH = P;
	double ans = f(LL);
	for(int i = 0; i < 10000; i++){
		double LM = (LL + MM) / 2;
		double MH = (MM + HH) / 2;
		double t1 = f(LL);
		double t2 = f(LM);
		double t3 = f(MM);
		double t4 = f(MH);
		double t5 = f(HH);
		double min = t1;
		if(t2 < min) min = t2;
		if(t3 < min) min = t3;
		if(t4 < min) min = t4;
		if(t5 < min) min = t5;
		ans = min;

		double L_ = LL;
		double M_ = MM;
		double H_ = HH;
		if(min == t1 || min == t2){
			MM = LM;
			HH = M_;
		}else if(min == t3){
			LL = LM;
			HH = MH;
	
	}else{
			LL = M_;
			MM = MH;
		}
	}
	printf("%.10f\n", ans);
	return 0;
}
