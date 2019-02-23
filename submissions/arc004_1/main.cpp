#include <stdio.h>
#include <math.h>

#define SQUARE(x) ((x) * (x))

int main(void)
{
	int N;
	scanf("%d", &N);
	int x[100];
	int y[100];
	for(int i = 0; i < N; i++){
		scanf("%d", &x[i]);
		scanf("%d", &y[i]);
	}
	double d_max = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < i; j++){
			double d = sqrt((double)SQUARE(x[i] - x[j]) + SQUARE(y[i] - y[j]));
			if(d > d_max) d_max = d;
		}

	}
	printf("%.15f\n", (double)d_max);

	return 0;
}
