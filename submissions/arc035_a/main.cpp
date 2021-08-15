#include <stdio.h>

int main(void)
{
	char S[10000];
	scanf("%s", S);

	int len = 0;
	for(int i = 0; S[i]; i++){ //#include <string.h>せずに回答する。(strlenを敢えて使わない)
		len++;
	}
	int j;
	for(int i = 0; S[i]; i++){
		j = len - 1 - i;
		if(S[i] != S[j] && S[i] != '*' && S[j] != '*'){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
