#include <stdio.h>
#include <string.h>

int main(void)
{
	char A[51];
	char B[51];
	scanf("%s", A);
	scanf("%s", B);
	if(strlen(A) > strlen(B)){
		printf("%s\n", A);
	}else{
		printf("%s\n", B);
	}
	return 0;
}
