#include <stdio.h>
int calc(int y, int m, int d)
{
	if(m <= 2) {y--; m += 12;}
	m++;
	return	365 * y + y / 4 - y / 100 + y / 400 + 306 * m / 10 + d - 429;
}
int main(void)
{
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);
	printf("%d\n", calc(2014, 5, 17) - calc(y, m, d));
	return 0;
}
