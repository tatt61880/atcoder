#include <stdio.h>
int main(void)
{
	int M, D;
	scanf("%d", &M);
	scanf("%d", &D);
	if(M % D == 0){
		puts("YES");
	}else{
		puts("NO");
	}
	return 0;
}
