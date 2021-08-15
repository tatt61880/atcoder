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

ll A[200000];
ll sumA[200001];
int main(){
	int N;
	cin >> N;
	rep(i, N) cin >> A[i];
	sumA[0] = A[0];
	rep(i, 1, N){
		sumA[i] = sumA[i - 1] + A[i];
	}
	map<ll, int> m;
	rep(i, N + 1) m[sumA[i]]++;
	ll count = 0;
	for(auto &x: m){
		ll y = x.second;
		count += y * (y - 1) / 2;
	}
	cout << (count) << endl;
	return 0;
}
