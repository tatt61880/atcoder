#include <stdio.h>
#include <string.h>

#define SQUARE(x) ((x) * (x))

int main(void)
{
	int N;
	scanf("%d", &N);
	int A[50];
	for(int i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}

	int t_max = -10000;
	for(int t = 0; t < N; t++){
		int a_sum_max = -10000;
		int t_sum;
		for(int a = 0; a &lt
; N; a++){
			if(a == t) continue;
			int a_sum_kouho = 0;
			int t_sum_kouho = 0;
			if(a < t){
				for(int i = a; i <= t; i++){
					if((i - a) % 2 == 0) { //一番左は1番目(奇数)。それはi - a = 0の時。というのが要注意。
						t_sum_kouho += A[i];
					}else{
						a_sum_kouho += A[i];
					}
				}
			}else{
				for(int i = t; i <= a; i++){
					if((i - t) % 2 == 0) {
						t_sum_kouho += A[i];
					}else{
						a_sum_kouho += A[i];
					}
				}
			}
			if(a_sum_kouho > a_sum_max){ // 青木君は最大が取れるのが複数ある場合には一番左を選択するので、「>=」ではなく、「>」。
				a_sum_max = a_sum_kouho;
				t_sum = t_sum_kouho;
				//printf("[debug]%d\n", a_sum_max);
			}
		}
		if(t_sum > t_max){
			t_max = t_sum;
		}
	}

	printf("%d\n", t_max);
	return 0;
}
