#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int min;
	scanf("%d", &min);
	for(int i = 1; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		if(a < min){
			min = a;
		}
	}
	printf("%d\n", min);
	return 0;
}
