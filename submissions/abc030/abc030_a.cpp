#include <stdio.h>

int main(void)
{
	int A, B, C, D;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	scanf("%d", &D);
	if(B * C > A * D) {
		puts("TAKAHASHI");
	}else if(B * C < A * D) {
		puts("AOKI");
	}else{
		puts("DRAW");
	}
	return 0;
}
