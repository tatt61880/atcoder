#include <iostream>
#include <string>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define PrintLn(X) cout << X << endl
typedef lo
ng long ll;

int dp[2048] = {1};

int main(){
	ll A, B;
	cin >> A >> B;
	int ans = 0;
	int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	for(ll i = A; i <= B; i++){
		int num = 0;
		Rep(j, 11){
			if(i % primes[j] == 0) num += (1 << j);
		}
		Rep(j, 2048){
			if((j & num) == 0){
				dp[j | num] += dp[j];
			}
		}
	}
	Rep(i, 2048){
		ans += dp[i];
	}
	PrintLn(ans);
	return 0;
}
