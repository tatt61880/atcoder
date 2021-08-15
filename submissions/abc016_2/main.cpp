#include <stdio.h>

int main(void)
{
	int A, B, C;
	scanf("%d%d %d", &A, &B, &C);

	if(B == 0){
		if(A == C){
			puts("?");
		}else{
			puts("!");
		}
	}else{
		if(A + B == C){
			puts("+");
		}else if(A - B == C){
			puts("-");
		}else{
			puts("!");
		}
	}
	return 0;
}
