#include <stdio.h>
#include <math.h>
int main(void)
{
	int N;
	int A, B, C;
	scanf("%d%d%d%d", &N, &A, &B, &C);
#define CHECK(X) (X != A && X != B && X != C)
	if(!CHECK(N)){
		puts("NO");
		return 0;
	}
	int count = 0;
	while(N > 0){
		if(CHECK(N - 3)){
			N -= 3;
		}else if(CHECK(N - 2)){
			N -= 2;
		}else if(CHECK(N - 1)){
			N -= 1;
		}else{
			puts("NO");
			return 0;
		}
		count++;
		if(count > 100){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
