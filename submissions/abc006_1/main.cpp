#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	if(n % 3 == 0){
		puts("YES");
	}else{
		puts("NO");
	}
	return 0;
}
