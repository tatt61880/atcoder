#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	char S[101];
	scanf("%s", S);

	int counts[4] = {0};
	for(int i = 0; i < N; i++){
		counts[S[i] - '1']++;
	}

	int max = counts[0];
	int min = counts[0];
	for(int i = 1; i < 4; i++){
		if(counts[i] < min) min = counts[i];
	
	if(counts[i] > max) max = counts[i];
	}
	printf("%d %d\n", max, min);

	return 0;
}
