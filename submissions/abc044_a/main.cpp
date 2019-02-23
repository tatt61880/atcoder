#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
int main(void)
{
	int N, K, X, Y;
	cin >> N >> K >> X >> Y;
	if(N < K){
		PrintLn(N * X);
	}else{
		PrintLn(K * X + (N - K) * Y);
	}
	return 0;
}
