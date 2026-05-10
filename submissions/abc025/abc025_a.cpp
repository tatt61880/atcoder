#include <stdio.h>
int main(void)
{
	char S[6];
	int N;
	scanf("%s", S);
	scanf("%d", &N);
	N--;
	printf("%c%c\n", S[N/5], S[N%5]);
	return 0;
}
