#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double PI = 3.14159265358979323846264338327950;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	int N, Q;
	cin >> N >> Q;
	double V[20001] = {0};
	Rep(i, N){
		int X;
		int R;
		int H;
		cin >> X >> R >> H;
		Rep(j, H){
#define Cubic(x) ((x)*(x)*(x))
			V[X + j + 1] += (double)R*R*(Cubic(H - j) - Cubic(H - j - 1)) * PI / 3 / H / H;
		}
	}
	Rep(i, 20000) V[i + 1] += V[i];
	Rep(i, Q){
		int A;
		int B;
		cin >> A >> B;
		printf("%.6f\n", V[B] - V[A]);
	}
	return 0;
}
