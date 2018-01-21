#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	char a, b;
	cin >> a >> b;
	PrintLn((a == b ? 'H' : 'D'));
	return 0;
}
