#include <stdio.h>

int main(void)
{
	int N, K;
	scanf("%d%d", &N, &K);
	int T[5][5];
	int max = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < K; j++){
			scanf("%d", &T[i][j]);
		}
	}
	for(int i = 0; i < (1 << 3 * N); i++){
		int ii = i;
		int xorsum = 0;
		for(int j = 0; j < N; j++){
			int k = ii % 8;
			if(k > K - 1){
				goto A;
			}
			xorsum ^= T[j][k];
			ii >>= 3;
		}
		if(xorsum == 0){
			puts("Found");
			return 0;
		}
A:;
	}
	puts("Nothing");
	return 0;
}
