#include <stdio.h>
#include <string.h>

int main(void)
{
	char S[101];
	char buf[101];
	int N;
	scanf("%s", S);
	buf[strlen(S)] = '\0';
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		for(int j = 0; j < strlen(S); j++){
			if(l <= j + 1 && j + 1 <= r){
				buf[j] = S[(r - 1) - (j - (l - 1))];
			}else{
				buf[j] = S[j];
			}
		}
		strcpy(S, buf);
	}
	printf("%s\n", S);
	return 0;
}
