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

void solve(int N, int A, int B){
	int ans = 0;
	rep(n, 1, N + 1){
		int num = n;
		int sum = 0;
		while(num){
			sum += num % 10;
			num /= 10;
		}
		if(A <= sum && sum <= B) ans += n;
	}
	printf("%d\n", ans);
}

int main(void){
	int N;
	int A;
	int B;
	scanf("%d", &N);
	scanf("%d", &A);
	scanf("%d", &B);
	solve(N, A, B);
	return 0;
}
