#include <stdio.h>
int main(void)
{
	int A, B;
	scanf("%d%d", &A, &B);
#define ABS(x) ((x) > 0 ? (x) : -(x))
	if(ABS(A) == ABS(B)){
		puts("Draw");
	}else if(ABS(A) > ABS(B)){
		puts("Bug");
	}else{
		puts("Ant");
	}
	return 0;
}
