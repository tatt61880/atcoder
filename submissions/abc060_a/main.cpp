#include <iostream>
#include <string>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	string a, b, c;
	cin >> a >> b >> c;

	cout << ((a[
a.size() - 1] == b[0] && b[b.size() - 1] == c[0]) ? "YES" : "NO") << endl;
	return 0;
}
