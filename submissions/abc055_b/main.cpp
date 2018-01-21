#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;
const int md = 1000000007;
int main(void)
{
	int N;
	cin >> N;
	ll ans = 1;
	Rep(i, N){
		ans *= (i + 1);
		ans %= md;
	}
	PrintLn(ans);
	return 0;
}
