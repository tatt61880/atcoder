#include <stdio.h>
#define max(x, y) (x) > (y) ? (x) : (y)
int main(void)
{
	int N[5];
	for(int i = 0; i < 5; i++){
		scanf("%d", &N[i]);
	}
	
	printf("%d\n", max(N[0] + N[3] + N[4], N[1] + N[2] + N[4]));
	return 0;
}
