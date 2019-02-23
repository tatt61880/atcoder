#include <stdio.h>

int main(void)
{
	int N;
	char S[1000][21];
	int P[1000];
	scanf("%d", &N);

	int sum = 0;
	for(int i = 0; i < N; i++){
		scanf("%s %d\n", &S[i], &P[i]);
		sum += P[i];
	}

	int namedFlag = 0;
	for(int i = 0; i < N; i++){
		if(sum < P[i] * 2) {
			printf("%s\n&#3
4;, S[i]);
			namedFlag = 1;
			break;
		}
	}
	if(namedFlag == 0){
		printf("atcoder\n");
	}
	return 0;
}
