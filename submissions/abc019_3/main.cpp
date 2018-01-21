#include <stdio.h>
#include <set>
int main(void)
{
	int N;
	scanf("%d", &N);
	std::set<long long> s;
	for(int i = 0; i < N; i++){
		long long a;
		scanf("%lld", &a);
		while(a % 2 == 0) a /= 2;
		s.insert(a);
	}
	printf("%d\n", s.size());
	int count = 0;
	return 0;
}
