#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define Rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PrintLn(X) cout << X << endl

typedef long long ll;
int a[2000];

int main(void)
{
	int N, Z, W;
	cin >> N >> Z >> W;
	Rep(i,
 N) cin >> a[i];

	int ans = abs(a[N - 1] - W);
	if(N > 1) ans = max(ans, abs(a[N - 2] - a[N - 1]));
	PrintLn(ans);
	return 0;
}
