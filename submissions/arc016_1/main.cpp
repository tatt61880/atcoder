#include <stdio.h>
int main(void)
{
	char M;
	getc(stdin);
	getc(stdin);
	M = getc(stdin);
	if(M == '1'){
		puts("2");
	}else{
		puts("1");
	}
	
	return 0;
}
