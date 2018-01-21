#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	double max = 0;
	for(int i = 0; i < n; i++){
		int a,b,c,d,e;
		scanf("%d%d%d%d%d", &a,&b,&c,&d,&e);
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
		max = MAX(max, a+b+c+d+e*110./900);
	}
	printf("%lf\n", max);
	return 0;
}
