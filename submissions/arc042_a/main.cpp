#include <stdio.h>

#define MAX 100000
int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	int n[MAX] = {0};

	int m[MAX];
	for(int i = 0; i < M; i++){
		scanf("%d", &m[i]);
	}

	int num = 0;
	int x[MAX] = {0};
	for(int i = M - 1; i >= 0; i--){
		if(n[m[i] - 1] == 0){
			n[m[i] - 1] = 1;
			x[num+&#4
3;] = m[i];
		}
	}
	for(int i = 0; x[i]; i++){
		printf("%d\n", x[i]);
	}
	for(int i = 0; i < N; i++){
		if(n[i] == 0){
			printf("%d\n", i + 1);
		}
	}
	return 0;
}

