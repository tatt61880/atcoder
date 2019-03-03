//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
typedef long long ll;
const int MOD = 1e9+7;
//}}}
int main(){
	int N;
	cin >> N;
	map<char, ll> m;
	rep(i, N){
		string s;
		cin >> s;
		m[s[0]]++;
	}
	char arr[] = "MARCH";
	ll ans = 0;
	rep(i, 5){
		rep(j, i + 1, 5){
			rep(k, j + 1, 5){
				ans += m[arr[i]] * m[arr[j]] * m[arr[k]];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
