#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
int main(void)
{
	int n, a, b;
	cin >> n >> a >> b;
	int ans = a + b - n;
	if(ans < 0) ans = 0;
	PrintLn(ans);
	return 0;
}
