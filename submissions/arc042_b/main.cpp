#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	double x, y;
	cin >> x >> y;
	int N;
	cin >> N;
	double X[100];
	double Y[100];
	Rep
(i, N) cin >> X[i] >> Y[i];
	X[N] = X[0];
	Y[N] = Y[0];
	double m = 0;
	Rep(i, N){
		double l = sqrt(pow(X[i] - X[i+1], 2) + pow(Y[i] - Y[i+1], 2));
		double d = abs((X[i] - x) * (Y[i+1] - y) - (X[i+1] - x) * (Y[i] - y)) / l;
		if(m == 0) m = d;
		m = min(m, d);
	}
	printf("%.10f\n", m);
	return 0;
}
