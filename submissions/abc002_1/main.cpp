#include <stdio.h>

int main(void)
{
	long long int X;
	long long int Y;
	scanf("%lld %lld", &X, &Y);
	printf("%lld\n", X > Y ? X : Y);
	return 0;
}
