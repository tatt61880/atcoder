#include <stdio.h>

int main(void)
{
	int N, M;
	scanf("%d %d\n", &N, &M);
	int S[12][12] = {{0}};
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d %d\n", &a, &b);
		a--;
		b--;
		S[a][b] = 1;
	}
	for(int i = 0; i < N; i++){
		S[i][i] = 1;
	}

	int ans = 0;
	int count;
	for(int n = 1; 
n < 1 << 12; n++){
		count = 0;
		for(int k = 0; k < N; k++){
			if((n >> k) & 1) count++;
		}
		if(count <= ans) goto A;
		for(int i = 0; i < N; i++){
			for(int j = 0; j <= i; j++){
				if(((n >> i) & (n >> j) & 1) && S[j][i] == 0){
					goto A;
				}
			}
		}
		ans = count;
A:;
	}
	printf("%d\n", ans);
#if 0
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%d ", S[i][j]);
		}
		puts("");
	}
#endif
	return 0;
}
