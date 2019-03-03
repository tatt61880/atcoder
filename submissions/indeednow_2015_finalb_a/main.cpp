#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
typedef long long LL;
LL MOD = 1000000007;
LL pow_mod(LL a, LL b){
	LL res = 1;
	while(b > 0){
		if(b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}
 
LL num(int n){
	LL ret = 1;
	ret *= pow_mod(n, 2);
	ret %= MOD;
	ret *= pow_mod(n + 1, 2);
	ret %= MOD;
	ret *= pow_mod(8, MOD - 2);
	ret %= MOD;
	LL ret2 = 1;
	ret2 *= n;
	ret2 %= MOD;
	ret2 *= n + 1;
	ret2 %= MOD;
	ret2 *= 2 * n + 1;
	ret2 %= MOD;
	ret2 *= pow_mod(12, MOD - 2);
	ret2 %= MOD;
	return (ret + ret2) % MOD;
}
int main(void)
{
	int A, B;
	cin >> A >> B;
	PrintLn((MOD + num(B) - num(A-1)) % MOD);
	return 0;
}
