#include <stdio.h>
int main(void)
{
	int a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	printf("%d\n", 1 + (a < b) + (a < c));
	printf("%d\n", 1 + (b < a) + (b < c));
	printf("%d\n", 1 + (c < a) + (c < b));
	return 0;
}
