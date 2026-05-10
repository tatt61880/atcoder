#include <stdio.h>

void rec(char *s, int N)
{
	if(N == 0){
		printf("%s\n", s);
	}else{
		char str[10];
		for(char c = 'a'; c <= 'c'; c++){
			sprintf(str, "%s%c", s, c);
			rec(str, N - 1);
		}
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	rec("", N);
	return 0;
}
