#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	int arr[100] = {0};
	int N, Q;
	cin >> N >> Q;
	Rep(i, Q){
		int L, R, T;
	
	cin >> L >> R >> T;
		For(j, L - 1, R){
			arr[j] = T;
		}
	}
	
	Rep(i, N){
		PrintLn(arr[i]);
	}
	return 0;
}
