#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
int main(void)
{
	int X, t;
	cin >> X >> t;
	int ans = X - t;
	if(ans < 0) ans = 0;
	PrintLn(ans);
	return 0;
}
