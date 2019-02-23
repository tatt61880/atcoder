#include <stdio.h>

int main(void)
{
	int N;
	int S[30000];
	int E[30000];

	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d-%d\n", &S[i], &E[i]);
	}

	int T[290] = {0};
	for(int i = 0; i < N; i++){
		int s = (S[i] / 100) * 12 + (S[i] % 100) / 5;
		int e = (E[i] / 100) * 12 +
 (E[i] % 100 + 4) / 5;
		for(int j = s; j < e; j++){
			T[j] = 1;
		}
	}

	int sFlag = 1;
	int eFlag = 0;
	for(int i = 0; i < 290; i++){
		if(sFlag && T[i]){
			sFlag = 0;
			eFlag = 1;
			printf("%02d%02d-", i / 12, (i % 12) * 5);
		}
		if(eFlag && !T[i]){
			sFlag = 1;
			eFlag = 0;
			printf("%02d%02d\n", i / 12, (i % 12) * 5);
		}
	}
	return 0;
}
