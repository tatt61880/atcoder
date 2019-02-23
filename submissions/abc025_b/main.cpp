#include <stdio.h>

int main(void)
{
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);

	int pos = 0;
	for(int i = 0; i < N; i++){
		char S[5];
		int d;
		scanf("%s%d", S, &d);
		if(d < A) d = A;
		if(d > B) d = B;
		if(S[0] == 'W') d *= -1;
		pos += d;
	}

	if(pos == 0){
		puts("0&#3
4;);
	}else if(pos > 0){
		printf("East %d\n", pos);
	}else{
		printf("West %d\n", -pos);
	}
	return 0;
}
