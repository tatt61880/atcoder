#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
ll a[300000];
int main(void)
{
	int N;
	cin >> N;
	Rep(i, N * 3) cin >> a[i];
	ll ans = 0;
	sort(a, a + N * 3);
	Rep(i, N){
		ans += a[3 * N - 2 - i * 2];
	}
	PrintLn(ans);
	return 0;
}
