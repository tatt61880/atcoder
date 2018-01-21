#include <cstdio>
#include <climits>
#define Rep(i, n) for(int i = 0; i < (n); i++)
typedef long long LL;
int main(void)
{
	int N;
	scanf("%d", &N);
	Rep(i, N){
		LL A, B;
		scanf("%lld %lld", &A, &B);
		if(A == LLONG_MIN && B == -1){
			printf("%lld%d\n", -(LLONG_MIN / 10), -(LLONG_MIN % 10));
		}else{
			printf("%lld\n", A / B);
		}
	}
	return 0;
}
