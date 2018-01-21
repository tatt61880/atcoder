#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int sec = N % 60;
	N /= 60;
	int min = N % 60;
	N /= 60;
	int hour = N;
	printf("%02d:%02d:%02d\n", hour, min, sec);
	return 0;
}
