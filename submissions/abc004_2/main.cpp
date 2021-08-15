#include <stdio.h>

int main(void)
{
	char B[4][4];
	for(int i = 0; i < 4; i++){
		scanf("%c %c %c %c\n", &B[i][0], &B[i][1], &B[i][2], &B[i][3]);
	}
	for(int i = 3; i >= 0; i--){
		printf("%c %c %c %c\n", B[i][3], B[i][2], B[i][1], B[i][0]);
	}
	return 0;
}
