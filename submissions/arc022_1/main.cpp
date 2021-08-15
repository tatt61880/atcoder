#include <stdio.h>

int main(void)
{
	char S[101];
	scanf("%s", S);
	enum {
		I,
		C,
		T,
		OK
	};
	int c = I;

	for(int i = 0; S[i] != '\0'; i++){
		switch(c){
		case I:
			if(S[i] == 'i' || S[i] == 'I'){
				c++;
			}
			break;
		case C:
			if(S[i] == 'c' || S[i] == 'C'){
				c++;
			}
			break;
		case T:
			if(S[i] == 't' || S[i] == 'T'){
				c++;
			}
			break;
		}
	}
	if(c == OK){
		puts("YES");
	}else{
		puts("NO");
	}
	return 0;
}
