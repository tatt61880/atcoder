#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	N %= 30;

	int card[6] = {1, 2, 3, 4, 5, 6};
	for(int i = 0; i < N; i++) {
		int temp = card[i % 5];
		card[i % 5] = card[i % 5 + 1];
		card[i % 5 + 1] = temp;
	}

	for(int i = 0; i < 6; i++){
		printf("%d", card[i]);
	}
	puts(&#
34;");

	return 0;
}
