#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	char S[101];
	scanf("%s", S);
	int sum = 0;
	for(int i = 0; i < N; i++){
		sum += 'E' - S[i];
		if(S[i] == 'F') sum++;
	}
	printf("%.15f\n", (double)sum / N);
	return 0;
}
