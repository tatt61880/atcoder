#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PrintLn(X) cout << X << endl
typedef long long ll;
int main(void)
{
	int N, M;
	cin >> N >> M;
	ll ans = 1;
	Rep(i, M) ans *= 2;
	ans *= (1900 * M + 100 * (N - M));
	PrintLn(ans);
	return 0;
}
