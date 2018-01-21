#include <stdio.h>
int main(void)
{
	char c1, c2;
	scanf("%c%c", &c1, &c2);
	if(c1 == 'S'){
		puts("0");
	}else if(c1 == 'M'){
		puts("5");
	}else if(c1 == 'T' && c2 == 'u'){
		puts("4");
	}else if(c1 == 'W'){
		puts("3");
	}else if(c1 == 'T'){
		puts("2");
	}else if(c1 == 'F'){
		puts("1");
	}
	
	return 0;
}
