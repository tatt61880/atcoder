#include <stdio.h>
int main(void)
{
	long long N;
	scanf("%lld", &N);
	if(N == 2 || N == 3 || N ==5){
		puts("Prime");
	}else if(N == 1 || N % 2 == 0 || N % 3 == 0 || N % 5 == 0){
		puts("Not Prime");
	}else{
		puts("Prime");
	}
	return 0;
}
