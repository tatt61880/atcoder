#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define PrintLn(X) cout << (X) << endl
int main(void)
{
	int N, K;
	cin >> N >> K;
	string a[100];
	Rep(i, N) cin >> a[i];
	sort(a, a + N);
	Rep(i, N) cout << a[N - 1 - i];
	cout << endl;
	return 0;
}
