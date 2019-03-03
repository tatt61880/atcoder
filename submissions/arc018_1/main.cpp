#include <stdio.h>
int main(void)
{
	double H, B;
	scanf("%lf%lf", &H, &B);
	printf("%lf\n", B * H * H / 10000);
	return 0;
}
