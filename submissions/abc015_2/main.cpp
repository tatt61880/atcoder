#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int sum = 0;
	int count = 0;
	for(int i = 0; i < N; i++){
		int A;
		scanf("%d", &A);
		if(A){
			sum += A;
			count++;
		}
	}
	sum += count - 1;
	printf("%d\n", sum / count);
	return 0;
}
