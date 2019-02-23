#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll MOD = 1000000007;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

ll a[100000];
int digit(int num){
	int res = 0;
	while(num){
		res++;
		num /= 10;
	}
	return res;
}
int main(void)
{
	i
nt N;
	cin >> N;
	Rep(i, N){
		cin >> a[i];
	}

	ll ans = a[0];
	Rep(i, N){
		if(i == 0) continue;
		int dig = digit(a[i]);
		Rep(j, dig){
			ans *= 10;
		}
		ans += a[i];
		ans %= MOD;
	}
	PrintLn(ans);
	return 0;
}
