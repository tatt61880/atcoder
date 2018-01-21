#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void)
{
	long long a, b, k, l;
	scanf("%lld %lld %lld %lld", &a, &b, &k, &l);
	int p = k / l;
	long long ans;
	if(k % l == 0){
		ans = p * b;
	}else{
		k -= p * l;
		ans = min(p * b + k * a, (p + 1) * b);
	}
	printf("%lld\n", ans);
	return 0;
}
