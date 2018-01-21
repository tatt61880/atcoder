#include <stdio.h>
int main(void)
{
	char S[11];
	char T[11];
	scanf("%s", &S);
	scanf("%s", &T);
	int win = 1;
	for(int i = 0; S[i] != '\0' || T[i] != '\0'; i++){
		if(S[i] != T[i]){
			if(S[i] == '@' && (T[i] == 'a' || T[i] == 't' || T[i] == 'c' || T[i] == 'o'  || T[i] == 'd' || T[i] == 'e' || T[i] == 'r')){
				continue;
			}
			if(T[i] == '@' && (S[i] == 'a' || S[i] == 't' || S[i] == 'c' || S[i] == 'o'  || S[i] == 'd' || S[i] == 'e' || S[i] == 'r')){
				continue;
			}
			win = 0;
		}
	}
	if(win){
		printf("You can win\n");
	}else{
		printf("You will lose\n");
	}
	return 0;
}
