#include <iostream>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define PrintLn(x) cout << x << endl;

int f(int n){
	if(n < 10){
		return n;
	}else{
		return 19 - n;
	}
}

int main(void)
{
	int N;
	cin >> N;
	int Max = 1;
	Rep(i, N) Max *= 10;
	Max--;
	PrintLn(Max);
	Rep(j, N) cout << 0;
	cout << endl;
	Rep(i, Max){
		int d = 1;
		char num[6] = {0};
		Rep(j, N){
			num[N - 1 - j] = f(((i + 1) / d) % 20) + '0';
			d *= 10;
		}
		PrintLn(num);
	}
	return 0;
}
