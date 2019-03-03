#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	int N;
	cin >> N;
	int x = 800 * N;
	int y = 200 * (N / 15);
	PrintLn(x - y);
	return 0;
}
