#include <stdio.h>

int main(void)
{
	int N, M, A, B;
	scanf("%d%d%d%d", &N, &M, &A, &B);
	for(int i = 0; i < M; i++){
		int a;
		scanf("%d", &a);
		if(N <= A){
			N += B;
		}
		N -= a;
		if(N < 0){
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("complete\n");
	
	return 0;
}
