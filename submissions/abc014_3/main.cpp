#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
#define MAX 100000
//#define MAX 100
	long long a[MAX];
	long long b[MAX];
	for(int i = 0; i < N; i++){
		scanf("%lld%lld", &a[i], &b[i]);
	}
	// いもす法により求める。
	int s[MAX * 10 + 2] = {0};
	for(int i = 0; i < N; i++){
		s[a[i]]++;
		s[b[i] + 1]--;
	}
	for(int i = 1; i < MAX * 10 + 2; i++){
		s[i] += s[i - 1];
	}
	int max = 0;
	for(int i = 0; i < MAX * 10 + 2; i++){
		if(s[i] > max) max = s[i];
		//printf("%d %d\n", i, s[i]);
	}
	printf("%d\n", max);
	return 0;
}
