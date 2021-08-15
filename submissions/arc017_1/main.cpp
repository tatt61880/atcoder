#include <stdio.h>


int main(void)
{
	int N;
	scanf("%d", &N);
	for(int i = 2; i < N; i++){
		if(N % i == 0){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
