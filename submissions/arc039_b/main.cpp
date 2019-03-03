#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
LL pow_mod(LL a, LL b){
	LL res = 1;
	while(b > 0){
		if(b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}
 
LL fact_mod(LL n){
	LL res = 1;
	Rep(i, n) res = (res * (i + 1)) % MOD;
	return res;
}
 
LL comb_mod(LL n, LL r){
	LL res = 1;
	Rep(i, r) res = (res * (n - i)) % MOD;
	return (res * pow_mod(fact_mod(r), MOD - 2)) % MOD;
}
 
int main(void)
{
	int N, K;
	cin >> N >> K;
	cout << comb_mod(N + (N > K) * (K - 1), K % N) << endl;
	return 0;
}
