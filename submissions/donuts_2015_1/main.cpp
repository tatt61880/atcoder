#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>

int main(void)
{
	double R, D;
	scanf("%lf %lf", &R, &D);
	printf("%.3f\n", 2 * R * R * D * M_PI * M_PI);
}
