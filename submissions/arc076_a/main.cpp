#include <iostream>
#include <cstdlib>
using namespace std;

typedef long long ll;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int N, M;
	cin >> N >> M;
	ll ans = 1;
	const ll MD = 1000000007;
	if(abs(N - M) <= 1){
		if(abs(N - M) == 0) ans = 2;
		Rep(i, N){
			ans *= (i + 1);
			ans %= MD;
		}
		Rep(i, M){
			ans *= (i + 1);
			ans %= MD;
		}
	}else{
		ans = 0;
	}
	PrintLn(ans);
	return 0;
}
