#include <stdio.h>

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	long long A[100001] = {0};
	long long sum = 0;
	for(int i = 0; i < N; i++){
		int l, r, s;
		scanf("%d%d%d", &l, &r, &s);
		A[l - 1] += s;
		A[r] -= s;
		sum += s;
	}
	// いもす法によって、各座標が何点分の区間で覆われているかを計算。
	for(int i = 
1; i <= M; i++){
		A[i] += A[i - 1];
	}
	long long min = A[0];
	for(int i = 0; i < M; i++){
		if(A[i] < min) min = A[i];
	}
	// すべてが覆われているということがないように、できるだけ少ない得点分の区間(の得点)を取り除く。
	printf("%lld\n", sum - min);
	return 0;
}
