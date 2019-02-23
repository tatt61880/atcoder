#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i = (int)(begin), i##_end = (int)(end); i < i##_end; ++i)
#define repN(a) repX a
#defi
ne repX(a0,a1,a2,x,...) x

void solve(string a, string b){
	ll n = stoi(a + b);
	bool ans = false;
	rep(i, 1000){
		if(i * i == n){
			ans = true;
			break;
		}
	}
	printf("%s\n", ans ? "Yes" : "No");
}

int main(void){
	string a;
	string b;
	cin >> a;
	cin >> b;
	solve(a, b);
	return 0;
}
