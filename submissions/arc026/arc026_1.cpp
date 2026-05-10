#include <stdio.h>

int main(void)
{
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);

	if(N > 5){
		printf("%d\n", N * A - 5 * (A-B));
	}else{
		printf("%d\n", N * B);
	}
	return 0;
}
