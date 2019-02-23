#include <stdio.h>
int main(void)
{
	int N, L;
	scanf("%d%d", &N, &L);
	char S[100000];
	scanf("%s", S);

	int ans = 0;
	int tab = 1;
	for(int i = 0; i < N; i++){
		if(S[i] == '+'){
			tab++;
		}else{
			tab--;
		}
		if(tab > L){
			ans++;
			tab = 1;
		}
	}

	printf("
%d\n", ans);
	return 0;
}
