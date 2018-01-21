#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	if(a == b) PrintLn(c);
	if(a == c) PrintLn(b);
	if(c == b) PrintLn(a);
	return 0;
}
