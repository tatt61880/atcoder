#include <iostream>
#include <cmath>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (n); i++)

int main(void)
{
	int N;
	cin >> N;
	int ans = 0;
	Rep(i, N){
		int A;
		cin >> A;
		ans += abs(i+1-A);
	}
	PrintLn(ans / 2);
	return 0;
}
