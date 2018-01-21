#include <iostream>
using namespace std;
#define PrintLn(X) cout << (X) << endl
typedef long long LL;
LL f(int N){
	int NN = N;
	LL ret = 0;
	LL x = 1;
	while(N){
		ret += x * (N % 10);
		N /= 10;
		x *= NN;
	}
	return ret;
}
int main(void)
{
	LL A;
	cin >> A;
	while(1){
		static int N = 10;
		LL num = f(N);
		if(num == A){
			PrintLn(N);
			return 0;
		}else if(num > A){
			PrintLn(-1);
			return 0;
		}
		N++;
	}
}
