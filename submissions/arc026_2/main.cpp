#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL MOD = 1000000007;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int main(void){
	LL n;
	cin >> n;
	LL N = 2 * n;
	LL sum = 1;
	int primes[200000] = {2, 3};
	int primes_count = 2;
	int sqrt_n = sqrt(n + 1);
	for(int i = 5; i <= sqrt_n * 2; i += 2){
		bool f = true;
		Rep(j, primes_count){
			if(i % primes[j] == 0) f = false;
		}
		primes[primes_count++] = i;
	}
	for(int i = 0; primes[i] <= sqrt(n + 1); ++i){
		LL a = 1;
		LL b = 1;
		while(n % primes[i] == 0){
			n /= primes[i];
			a *= primes[i];
			b += a;
		}
		if(b != 1) sum *= b;
	}
	if(n != 1) sum *= (n + 1);
	if(sum == N){
		PrintLn("Perfect");
	}else if(sum > N){
		PrintLn("Abundant");
	}else{
		PrintLn("Deficient");
	}
	return 0;
}
