#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	int N;
	cin >> N;
	const int NMAX = 100000;
	int D[NMAX + 1] = {0};
	Rep(i, N){
		int d;
		cin >> d;
		D[d]++;
	}
	int N4[NMAX + 2] = {0};
	for(int i = NMAX; i > 0; i--){
		N4[i] = N4[i + 1] + D[i];
	}
	LL N3[NMAX / 2 + 2] = {0};
	for(int i = NMAX / 2; i > 0; i--){
		N3[i] = N3[i + 1] + D[i] * N4[i * 2];
		N3[i] %= MOD;
	}
	LL N2[NMAX / 4 + 2] = {0};
	for(int i = NMAX / 4; i > 0; i--){
		N2[i] = N2[i + 1] + D[i] * N3[i * 2];
		N2[i] %= MOD;
	}
	LL N1[NMAX / 8 + 2] = {0};
	for(int i = NMAX / 8; i > 0; i--){
		N1[i] = N1[i + 1] + D[i] * N2[i * 2];
		N1[i] %= MOD;
	}
	PrintLn(N1[1]);
	return 0;
}
