#include <stdio.h>
#include <string.h>
int main(void)
{
	char S[100001];
	scanf("%s", S);
	int answer = 0;
	int flag = 1;
	int len = strlen(S);
	for(int i=0; i<len; i+=2){
		char op = S[i+1];
		switch(op){
		case '+':
			if(S[i] != '0' && flag){
				answer++;
			}
			flag = 1;
			break;
		case '*':
			if(S[i] == '0'){
				flag = 0;
			}
			break;
		case '\0':
			if(S[i] != '0' && flag){
				answer++;
			}
			break;
		}
	}
	printf("%d\n", answer);
	return 0;
}
