#include <stdio.h>
int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	int T[10][10] = {{0}};
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		T[a - 1][b - 1] = 1;
		T[b - 1][a - 1] = 1;
	}
	for(int i = 0; i < N; i++){
		int count = 0;
		for(int j = 0; j < N; j++){
			if(i == j || T[i][j]) continue;
			for(int k = 0; k < N; k++){
				if(i == k || j == k) continue;
				if(T[i][k] && T[j][k]) {
					count++;
					break; //同じ「友達の友達」を別経路で複数回数えないように！
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
