#include <iostream>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	int N;
	cin >> N;
	char A[50][50];
	Rep(i, N) Rep(j, N) cin >> A[i][j];
	Rep(j, N){
		for(int i=N-1; i >= 0; i--) cout << A[i][j];
		cout << endl;
	}
	return 0;
}
