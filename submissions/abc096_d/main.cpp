//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const int MOD = 1e9+7;
//}}}

int a[55];
int primes[55555 * 5];
int main(){
	int N;
	cin >> N;
	int primeCount = 0;
	primes[primeCount++] = 2;
	int count = 0;
	rep(n, 3, 55555 * 5){
		bool f = true;
		rep(j, primeCount){
			if(n % primes[j] == 0){
				f = false;
				break;
			}
		}
		if(f){
			primes[primeCount++] = n;
			if(n % 10 == 1){
				count++;
				printf("%d", n);
				if(count == N){
					return 0;
				}
				printf(" ");
			}
		}
	}
	return 0;
}
