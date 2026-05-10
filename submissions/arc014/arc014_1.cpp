#include <stdio.h>


int main(void)
{
	int N;
	scanf("%d", &N);
	
	if(N % 2){
		puts("Red");
	}else{
		puts("Blue");
	}
	
	return 0;
}
