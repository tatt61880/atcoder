#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define Rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PrintLn(X) cout << X << endl
int main(void)
{
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	int ans = a[
0] + a[1];
	PrintLn(ans);
	return 0;
}
