#include <cstdio>
int main(void)
{
	int a[20] = {1, 1, 2};
	for(int i = 3; i < 20; i++){
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	}
	printf("%d00\n", a[19]);
	return 0;
}
