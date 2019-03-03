#include <stdio.h>
int main(void)
{
	char S[1000];
	scanf("%s", S);
	int strlength = 0;
	for(int i = 0; S[i]; i++){
		strlength++;
	}
	for(int i = 0; S[i]; i++){
		if(S[i] != S[strlength - 1 - i]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
