#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int main(void)
{
	int N, Q;
	cin >> N >> Q;
	int A[200002] = {0};
	Rep(i, Q){
		int l, r;
		cin >> l >> r;
		A[l]++;
		A[r + 1]++;
	}
	Rep(i, N + 1){
		A[i + 1] += A[i];
	}
	For(i, 1, N + 1) cout << (A[i] % 2);
	cout << endl;
	return 0;
}
