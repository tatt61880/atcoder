#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
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
	int W, H;
	cin >> W >> H;
	W--;
	H--;
	PrintLn(comb_mod(W + H, min(W, H)));
	return 0;
}
