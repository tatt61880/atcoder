#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int sum = 0;
	for(int i = 0; i < N; i++){
		int m;
		scanf("%d", &m);
		if(m < 80){
			sum += 80 - m;
		}
	}
	printf("%d\n", sum);
	return 0;
}
