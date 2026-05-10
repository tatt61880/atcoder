#include <stdio.h>


int min(int h, int m){
	return h * 60 + m;
}

int main(void)
{
	int h, m;
	scanf("%d%d", &h, &m);

	printf("%d\n", min(18, 0) - min(h, m));
	return 0;
}
