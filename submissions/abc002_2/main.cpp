#include <stdio.h>
#include <string.h>
int main(void)
{
	char W[32];
	scanf("%s", &W);
	for(int i = 0; i < strlen(W); i++){
		if(W[i] == 'a' || W[i] == 'i' || W[i] == 'u' || W[i] == 'e' || W[i] == 'o' ){
		}else{
			printf("%c", W[i]);
		}
	}
	puts("");
	return 0;
}
