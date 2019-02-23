#include <stdio.h>

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	long long X, Y;
	scanf("%lld%lld", &X, &Y);
	#define MAX 100000
	long long a[MAX];
	long long b[MAX];
	for(int i = 0; i < N; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 0; i < M; i++){
		scanf("%lld&
#34;, &b[i]);
	}

	enum site{
		A,
		B
	};
	int current_site = A;
	int i_a = 0;
	int i_b = 0;
	int a_max = N;
	int b_max = M;
	int count = 0;
	long long current_time = 0;
	while(1){
		if(current_site == A){
			for(;i_a < a_max; i_a++){
				if(a[i_a] >= current_time){
					current_site = B;
					current_time = a[i_a] + X;
					count++;
					break;
				}
			}
			if(i_a == a_max) break;
		}else{
			for(;i_b < b_max; i_b++){
				if(b[i_b] >= current_time){
					current_site = A;
					current_time = b[i_b] + Y;
					count++;
					break;
				}
			}
			if(i_b == b_max) break;
		}
	}

	printf("%d\n", count / 2);
	return 0;
}
