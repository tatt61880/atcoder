#include <iostream>
#include <algorithm>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (n); i++)

void invalid(void)
{
	PrintLn("invalid");
	exit(0);
}

int main(void)
{
	int n;
	cin >> n;
	int a[100];
	Rep(i, n) cin >> a[i];
	sort(a, a + n);
	int mn = a[0] + a[n - 1];
	int mx = a[0] + a[n - 1];
	Rep(i, n / 2){
		mn = min(mn, a[i] + a[n - 1 - i]);
		mx = max(mx, a[i] + a[n - 1 - i]);
	}
	PrintLn(mx - mn);
	return 0;
}
