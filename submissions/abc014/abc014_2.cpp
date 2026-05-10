#include <stdio.h>

int main(void)
{
	int n, X;
	scanf("%d%d", &n, &X);
	int sum = 0;
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		if((X >> i) & 1){
			sum += a;
		}
	}
	printf("%d\n", sum);
	return 0;
}
