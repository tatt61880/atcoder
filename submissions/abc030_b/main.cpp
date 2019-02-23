#include <stdio.h>

int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);

	n %= 12;
	double angle_n = n * 30 + 30 * m / 60.;
	double angle_m = 360 * m / 60.;

	double angle = 360 + (angle_n - angle_m);
	if(angle > 360){
		angle -= 360;
	}
	if(angle > 180){
		angle = 360 - angle;
	}
	printf("%f\n", angle);

	return 0;
}
