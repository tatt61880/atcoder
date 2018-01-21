#include <stdio.h>
int main(void)
{
	long long N;
	long long K[100000];
	scanf("%lld", &N);
	for(int i = 0; i < N - 1; i++){
		scanf("%lld", &K[i]);
	}
	printf("%lld", K[0]);
	for(int i = 1; i < N - 1; i++){
		if(K[i] < K[i - 1]){
			printf(" %lld", K[i]);
		} else {
			printf(" %lld", K[i - 1]);
		}
	}
	printf(" %lld\n", K[N - 2]);
	return 0;
}
