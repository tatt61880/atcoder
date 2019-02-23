#include <stdio.h>

int main(void)
{
	int a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	if(a > b){
		int t;
		t = a;
		a = b;
		b = t;
	}
	if(a > c){
		int t;
		t = a;
		a = c;
		c = t;
	}
	if(b > c){
		int t;
		t = b;
		b = c;
		c = t;
	}
	printf("%d\n", b);
	return 0;
}

