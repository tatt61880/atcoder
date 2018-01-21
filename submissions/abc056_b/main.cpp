#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	int w, a, b;
	cin >> w >> a >> b;
	int ab = a - b;
	if(ab < 0) ab *= -1;
	ab -= w;
	PrintLn((ab < 0 ? 0 : ab));
	return 0;
}
