#include <stdio.h>
#include <string.h>

#define SQUARE(x) ((x) * (x))

int main(void)
{
	int N;
	long long K;
	scanf("%d%lld", &N, &K);
	long long s[100001];
	s[0] = 1;
	for(int n = 1; n <= N; n++){
		scanf("%lld", &s[n]);
	}

	//例外処理。0を含む場合は除算ができないので。
	for(int n = 1; n <= N; n++){
		if(s[n] == 0){
			printf("%d\n", N); // 0を含む数列なので最長(求める値)はN
			return 0;
		}
	}

	long long p = 1;
	int r = 0;
	int max = 0;

	for(int l = 1; l <= N; l++){
		if(s[l] > K){
			p = 1;
			r = l;
			s[l] = 1;
			continue;
		}
		p /= s[l - 1];
		for(r++; r <= N; r++){
			p *= s[r];
			if(p > K){
				p /= s[r];
				break;
			}
		}
		r--;
		if(r - l + 1 > max) max = r - l + 1;
		//printf("[DEBUG] max = %d l = %d r = %d p=%lld\n", max, l, r, p);
	}
	printf("%d\n", max);
	return 0;
}
