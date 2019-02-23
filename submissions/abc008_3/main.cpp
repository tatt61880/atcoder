#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int C[100];
	for(int i = 0; i < N; i++){
		scanf("%d", &C[i]);
	}

	double ans = 0;
	for(int i = 0; i < N; i++){
		int target = C[i];
		int count = 0;
		for(int j = 0; j < N; j++){
			if(target % C[j] == 0){
				count+
+;
			}
		}
		//カウントしたコインの中からターゲットのコインが奇数番目になる確率が、ターゲットのコインが表を向いている確率p。
		double p = 0;
		for(int j = 1; j <= count; j+=2){
			// count枚中、j番目になる確率は 1 / count;
			p += (double)1 / count;
		}
		ans += p;
	}
	printf("%.10f\n", ans);
}
