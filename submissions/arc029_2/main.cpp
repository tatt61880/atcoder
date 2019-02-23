#include <iostream>
#include <cmath>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	double A, B;
	int N;
	double C, D;
	cin >> A >> B;
	if(A < B) swap(A, B);
	cin >> N;
	Rep(i, N){
		cin >> C >> D;
		if(
C < D) swap(C, D);
		if(C >= A){
			if(D >= B){
				PrintLn("YES");
			}else{
				PrintLn("NO");
			}
		}else{
			double t = asin(C/sqrt(A*A+B*B)) - atan(B/A);
			if(A * cos(t) + B * sin(t) <= D){
				PrintLn("YES");
			}else{
				PrintLn("NO");
			}
		}
	}
	return 0;
}
