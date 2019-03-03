#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
int main(void)
{
	int N, M;
	cin >> N >> M;
	int num = N * (N + 1) * (2 * N + 1) / 6;
	PrintLn(num % M);
	return 0;
}
