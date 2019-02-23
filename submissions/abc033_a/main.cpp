#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	if(n % 1111 == 0){
		printf("SAME\n");
	}else{
		printf("DIFFERENT\n");
	}
	return 0;
}
