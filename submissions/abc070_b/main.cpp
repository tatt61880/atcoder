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

int main(void){
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	int ans = 0;
	ans = max(0, (min(B, D) - max(A, C)));
	printf("%d\n", ans);
	return 0;
}
