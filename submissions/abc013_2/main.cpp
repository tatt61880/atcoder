#include <stdio.h>
int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = (a > b ? a - b : b - a);
	if(ans > 5) ans = 10 - ans;
	printf("%d\n", ans);
	return 0;
}
