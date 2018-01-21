#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int sum = 0;
	for(int i = 0; i < N; i++){
		int a;
		int b;
		scanf("%d%d", &a, &b);
		sum += a * b;
	}
	
	printf("%d\n", sum * 21 / 20);
	return 0;
}
