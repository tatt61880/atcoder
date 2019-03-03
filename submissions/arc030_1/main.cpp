#include <stdio.h>
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	if(n / 2 >= k){ // n >= 3なので、n == k == 1の場合の例外処理は不要。
		puts("YES");
	}else{
		puts("NO");
	}
	return 0;
}
