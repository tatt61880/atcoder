#include <stdio.h>
int main(void)
{
	int L, H;
	scanf("%d%d", &L, &H);
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int A;
		scanf("%d", &A);
		if(A < L){
			printf("%d\n", L - A);
		}else if(A > H){
			puts("-1");
		}else{
			puts("0");
		}
	}
	return 0;
}
