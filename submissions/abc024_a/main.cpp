#include <stdio.h>
int main(void)
{
	int A,B,C,K,S,T;
	scanf("%d%d%d%d%d%d", &A,&B,&C,&K,&S,&T);
	printf("%d\n", A*S+B*T - ((S+T>=K)? C * (S+T) : 0));
	return 0;
}
