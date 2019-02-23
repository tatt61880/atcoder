#include <stdio.h>
#include <math.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	int p = 2025 - N;
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			if(i * j == p){
				printf("%d x %d\n", i, j);
			}
		}
	}
	return 0;
}
