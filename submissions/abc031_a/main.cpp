#include <stdio.h>

int main(void)
{
	int A, D;
	scanf("%d", &A);
	scanf("%d", &D);
	if(A < D) {
		printf("%d\n", (A + 1) * D);
	}else{
		printf("%d\n", A * (D + 1));
	}
	return 0;
}
