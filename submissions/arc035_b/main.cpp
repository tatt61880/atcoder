#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int f(LL x){
	int ret = 0;
	while(x) ret += x % 10, x /= 10;
	return ret;
}
int main(void)
{
	int N;
	cin >> N;
	map<int, int> mp;
	Rep(i, N){
		int T;
		cin >> T;
		mp[T]++;
	}
	LL current_time = 0;
	LL total_penalty = 0;
	LL count = 1;
	for(auto& x:mp){
		Rep(i, x.second){
			count *= (i + 1);
			count %= MOD;
			current_time += x.first;
			total_penalty += current_time;
		}
	}
	PrintLn(total_penalty);
	PrintLn(count);
	
	return 0;
}
