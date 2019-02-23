#include <stdio.h>

int main(void)
{
	int a, b, c;
	int d, e, f;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	scanf("%d", &e);
	scanf("%d", &f);
	printf("%d\n", (a * b + c * d + e * f) / 10);
	return 0;
}
