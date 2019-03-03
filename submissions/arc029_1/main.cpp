#include <stdio.h>
int min(int h, int m){
	return h * 60 + m;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	int t[4];
	for(int i = 0; i < N; i++){
		scanf("%d", &t[i]);
	}
	int min = 10000000;
	for(int i = 0; i < (1 << N); i++){
		int l = 0;
		int r = 0;
		for(int j = 0; j < N; j++){
			((i >> j & 1) ? l : r) += t[j]; // ビットが立っていれば、左の肉焼き器で焼く。
		}
		if(l > r) r = l;
		if(min > r) min = r;
	}
	printf("%d\n", min);
	return 0;
}
