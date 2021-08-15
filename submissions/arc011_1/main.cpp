#include <stdio.h>

int main(void)
{
	int m, n, N;
	scanf("%d%d%d", &m, &n, &N);

	int sold = 0;
	int small = 0;
	while(N > 0){
		sold += N;
		small += N;
		N = small / m * n;
		small -= small / m * m;
	}
	printf("%d\n", sold);
	
	return 0;
}
