#include <iostream>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define PrintLn(X) cout << (X) << endl
#define MAX 100000
int main(void)
{
	int N;
	cin >> N;
	int S[MAX];
	int T[MAX];
	int SS[2 * MAX+1] = {0};
	Rep(i, N){
		cin >> S[i];
		cin >> T[i];
		SS[S[i]]++;
	}
	Rep(i, 2 * N) SS[i + 1] += SS[i];
	Rep(i, N) PrintLn(SS[T[i]] - SS[S[i]]);
	return 0;
}
