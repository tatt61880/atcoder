#include <stdio.h>
int main(void)
{
	int A[4][4];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			scanf("%d", &A[i][j]);
		}
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			if(A[i][j] == A[i][j+1] || A[j][i] == A[j+1][i]){
				puts("CONTINUE");
				return 0;
			}
		}
	}
	puts("GAMEOVER");
	return 0;
}
