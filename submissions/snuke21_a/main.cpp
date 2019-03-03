#include <cstdio>
#include <cmath>
//(k + 1) * k / 2 == n
//k^2 + k - 2n == 0
//k = (-1 + sqrt(8*n - 1))/2;
int main(void)
{
	long long n;
	scanf("%lld", &n);
	long long k = (sqrt(8 * n + 1) - 1) / 2;
	if(k * k + k == 2 * n){
		printf("%lld", k);
	}else{
		puts("-1");
	}
}
