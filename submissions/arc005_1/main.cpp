#include <stdio.h>
#include <string.h>
#define SQUARE(x) ((x) * (x))
int main(void)
{
	int N;
	scanf("%d", &N);
	int count = 0;
	for(int i = 0; i < N; i++){
		char S[102];
		scanf("%s", S);
		if(i == N - 1) S[strlen(S) - 1] = '\0'; // 文の最後の「.」を削除。
		if(strcmp(S, "TAKAHASHIKUN") == 0) count++;
		if(strcmp(S, "Takahashikun") == 0) count++;
		if(strcmp(S, "takahashikun") == 0) count++;
	}
	printf("%d\n", count);
	return 0;
}
