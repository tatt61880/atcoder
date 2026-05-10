#include <iostream>
#include <cstring>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int r = c - a;
	int u = d - b;
	Rep(i, r) cout << 'R';
	Rep(i, u) cout << 'U';
	Rep(i, r) cout << 'L';
	Rep(i, u) cout << 'D';
	cout << 'D';
	Rep(i, r + 1) cout << 'R';
	Rep(i, u + 1) cout << 'U';
	cout << 'L';
	cout << 'U';
	Rep(i, r + 1) cout << 'L';
	Rep(i, u + 1) cout << 'D';
	cout << 'R';
	return 0;
}
