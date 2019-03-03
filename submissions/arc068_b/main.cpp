#include <iostream>
using namespace std;
typedef long long ll;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int A[100000] = {0};
int main(void)
{
	int N;
	cin >> N;
	Rep(i, N){
		int a;
		cin >> a;
		A[a-1]++;
	}
	int n = 0;
	Rep(i, 100000){
		if(A[i] > 1){
			n += A[i] - 1;
		}
	}
	PrintLn(N - (n + 1) / 2 * 2);
	return 0;
}
