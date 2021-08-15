#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int a[100000];
ll s[100001];
int main(void)
{
	int N, K;
	cin >> N >> K;
	Rep(i, N) cin >> a[i];
	s[0] = 0;
	Rep(i, N + 1) s[i + 1] = s[i] + a[i];

	ll ans = 0;
	Rep(i, N - K + 1){
		ans += s[i + K] - s[i];
	}
	PrintLn(ans);
	return 0;
}
