#include <stdio.h>
int main(void)
{
	char S[1001];
	scanf("%s", S);
	char *p = S;
	while(*p != '\0'){
		char c = *p;
		int count = 1;
		while(*(++p) == c){
			count++;
		}
		printf("%c%d", c, count);
	}
	puts("");
	return 0;
}
