#include <stdio.h>
int main(void)
{
	int a, b, n;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &n);
	for(int i = n; ; i++) {
		if(i % a == 0 && i % b == 0){
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
