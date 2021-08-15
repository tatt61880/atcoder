#include <stdio.h>

int main(void)
{
	int N;
	long long H;
	long long A, B, C, D, E;
	scanf("%d%lld%lld%lld%lld%lld%lld", &N, &H, &A, &B, &C, &D, &E);

	long long min_cost = A * N;
	for(int i = 0; i <= N; i++){
		int j = ((N-i)*E - H - B*i >= 0) ? ((N-i)*E -H - B*i) / (D + E) + 1 : 0;
		if(j <= N - i){
			if(A * i + C * j < min_cost) min_cost = A * i + C * j;
		}
	}
	printf("%lld\n", min_cost);
	return 0;
}