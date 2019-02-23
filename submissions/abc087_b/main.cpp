#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i = (int)(begin), i##_end = (int)(end); i<i##_end; ++i)
#define repN(a) repX a
#define
 repX(a0,a1,a2,x,...) x

void solve(ll A, ll B, ll C, ll X){
	ll ans = 0;
	rep(a, A + 1){
		rep(b, B + 1){
			rep(c, C + 1){
				if(a * 500 + b * 100 + c * 50 == X) ans++;
			}
		}
	}
	printf("%lld\n", ans);
}

int main(void){
	ll A;
	ll B;
	ll C;
	ll X;
	scanf("%lld", &A);
	scanf("%lld", &B);
	scanf("%lld", &C);
	scanf("%lld", &X);
	solve(A, B, C, X);
	return 0;
}
