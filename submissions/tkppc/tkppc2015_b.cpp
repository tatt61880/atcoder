#include <cstdio>
#define rep(i, n) for(int i = 0; i < (n); i++)

int main(void)
{
	int n;
	scanf("%d", &n);
	int max = -1;
	int ans;
	rep(i, n){
		int a;
		scanf("%d", &a);
		if(a > max){
			max = a;
			ans = i;
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}
