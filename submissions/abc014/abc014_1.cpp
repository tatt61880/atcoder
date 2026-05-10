#include <stdio.h>

int main(void)
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	if(a % b == 0){
		puts("0");
	}else{
		printf("%d\n", b - a % b);
	}
	return 0;
}
