#include <stdio.h>


int min(int h, int m){
	return h * 60 + m;
}

int main(void)
{
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);

	while(1){
		N -= A;
		if(N <= 0){
			puts("Ant");
			return 0;
		}
		N -= B;
		if(N <= 0){
			puts("Bug");
			return 0;
		}
	}
	return 0;
}
