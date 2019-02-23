#include <cstdio>
using namespace std;

typedef long long LL;

#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	LL A, K;
	scanf("%lld %lld", &A, &K);

	LL wanted = 2000000000000;
	LL ans = 0;
	if (K == 0) {
		ans = wanted - A;
	} else {
		while(A < wanted){
			A += 1 + 
A * K;
			ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
