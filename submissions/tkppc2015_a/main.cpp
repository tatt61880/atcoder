#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (n); i++)
int main(void)
{
	int N;
	cin >> N;
	Rep(i, N){
		int A, B;
		cin >> A >> B;
		PrintLn(A + B);
	}
	return 0;
}
