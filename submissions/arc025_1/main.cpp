#include <stdio.h>
int main(void)
{
	int D[7];
	int J[7];
	for(int i = 0; i < 7; i++){
		scanf("%d", &D[i]);
	}
	for(int i = 0; i < 7; i++){
		scanf("%d", &J[i]);
	}
	int sum = 0;
	for(int i = 0; i < 7; i++){
		sum += D[i] > J[i] ? D[i] : J[i];
	}
	printf("%d\n", sum);
	return 0;
}
