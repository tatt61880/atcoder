#include <stdio.h>

int main(void)
{
	int N, K;
	scanf("%d%d", &N, &K);

	int t[100000];
	for(int i = 0; i < N; i++){
		scanf("%d", &t[i]);
	}

	for(int i = 2; i < N; i++){
		if(t[i] + t[i - 1] + t[i - 2] < K){
			printf("%d\n", i + 1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
