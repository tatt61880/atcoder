#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int x_a;
	int x_b;
	int x_c;
	int y_a;
	int y_b;
	int y_c;
	scanf("%d %d %d %d %d %d", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c);
	double ans;
	ans = abs((x_b - x_a) * (y_c - y_a) - (y_b - y_a) * (x_c - x_a)) * 0.5;
	
	printf("%.1f\n", ans);
	return 0;
}
