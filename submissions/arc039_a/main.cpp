#include <stdio.h>

int main(void)
{
	int A;
	int B;
	scanf("%d", &A);
	scanf("%d", &B);

	int max = A - B;
	int a;
	int b;
	b = B;
	a = 900 + A % 100;
	if(a - b > max) max = a - b;
	a = A / 100 * 100 + 90 + A % 10;
	if(a - b > max) max = a - b;
	a = A / 10 * 10 + 9;
	if(a - b > max) max = a - b;


	a = A;
	b = 100 + B % 100;
	if(a - b > max) max = a - b;
	b = B / 100 * 100 + B % 10;
	if(a - b > max) max = a - b;
	b = B / 10 * 10;
	if(a - b > max) max = a - b;

	printf("%d\n", max);
	return 0;
}

