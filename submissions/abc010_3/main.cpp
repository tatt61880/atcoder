#include <stdio.h>
#include <math.h>

int main(void)
{
	double Sx, Sy, Gx, Gy;
	double T, V;
	scanf("%lf%lf%lf%lf%lf%lf", &Sx, &Sy, &Gx, &Gy, &T, &V);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		double x, y;
		scanf("%lf%lf", &x, &y);
		if(sqrt(
(Sx - x)*(Sx - x) + (Sy - y) * (Sy - y)) + sqrt((Gx - x)*(Gx - x) + (Gy - y) * (Gy - y)) - 1e-10 <= V * T){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
