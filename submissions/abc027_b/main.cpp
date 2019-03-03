#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int sum = 0;
	int a[101];
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if(sum % N != 0){
		puts("-1");
		return 0;
	}
	int ave = sum / N; // 平均人数
	int sub_sum = 0;
	int sub_count = 0;
	int parts = 0;
	for(int i = 0; i < N; i++){
		sub_sum += a[i];
		sub_count++;
		if(sub_sum == sub_count * ave){
			sub_sum = 0;
			sub_count = 0;
			parts++;
		}
	}
	printf("%d\n", N - parts);
	return 0;
}
