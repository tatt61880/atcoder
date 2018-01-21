#include <iostream>
#include <cstdlib>
using namespace std;
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
#define PrintLn(X) cout << X << endl
typedef long long LL;
const LL MOD = 1000000007;
LL pow_mod(LL a, LL b){
	LL res = 1;
	while(b > 0){
		if(b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}
void zero(void){
	PrintLn("0");
	exit(0);
}
int main(void)
{
	int N;
	cin >> N;
	int A[100000];
	Rep(i, N) cin >> A[i];
	if(A[0]) zero();
	int count[100000] = {0};
	Rep(i, N) count[A[i]]++;
	if(count[0] != 1) zero();
	int sum = 0;
	LL ans = 1;
	For(i, 1, N){
		if(count[i] == 0) zero();
		ans = (ans * pow_mod(2, (LL)count[i]*(count[i] - 1)/2)) % MOD;
		Loop(count[i]){
			ans = (ans * (pow_mod(2, count[i - 1]) + MOD - 1)) % MOD;
		}
		sum += count[i];
		if(sum == N - 1) break;
	}
	PrintLn(ans);
	return 0;
}
