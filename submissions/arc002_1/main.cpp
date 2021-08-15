#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	if(N % 400 == 0 || (N % 100 != 0 && N % 4 == 0)){
		puts("YES");
	}else{
		puts("NO");
	}

	return 0;
}
