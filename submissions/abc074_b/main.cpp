#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i = (int)(begin), i##_end = (int)(end); i < i##_end; ++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x

int main(void){
	int N;
	int K;
	cin >> N;
	cin >> K;

	int ans = 0;
	rep(i, N){
		int x;
		cin >> x;
		ans += min(x, abs(x - K)) * 2;
	}
	printf("%d\n", ans);
	return 0;
}
