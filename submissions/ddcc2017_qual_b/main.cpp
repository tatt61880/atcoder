#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	PrintLn(1728 * A + 144 * B + 12 * C + D);
	return 0;
}
