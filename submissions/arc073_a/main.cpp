#include <iostream>
using namespace std;

typedef long long ll;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int N, T;
	cin >> N >> T;

	ll ans = 0;
	ll last = -T;
	Rep(i, N){
		int t;
		cin >> t;
		ans += (t > last + T) ? T :
 (t - last);
		last = t;
	}
	PrintLn(ans);
	return 0;
}
