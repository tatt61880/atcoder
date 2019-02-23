#include <stdio.h>

int main(void)
{
	int R, C, K;
	scanf("%d%d%d", &R, &C, &K);
	char S[501];

	int data[500][500]; // 点(i, j)を中央として、左右に白マスが何マス分続いているかを記録する。(左右で少ない方の値を採用)
						// ※(i, j)と書いていますが、iは高さ方向です。
	for(int i = 0; i < R; i++){
		scanf("%s", S);
		for(int j = 0; j < C; j++){
			int r =
 0; //(i, j)から右側にどれだけ白マスが連続しているか。
			int l = 0; //(i, j)から左側にどれだけ白マスが連続しているか。
			for(int k = j; k < C; k++){
				if(S[k] == 'x') break;
				r++;
			}
			for(int k = j; k >= 0; k--){
				if(S[k] == 'x') break;
				l++;
			}
			//printf("[%d %d(j=%d)]", r, l, j);
			data[i][j] = (r < l) ? r : l;
		}
		//printf("%s\n", S);
	}

#if 0
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			printf("%d", data[i][j]);
		}
		printf("\n");
	}
#endif

	int count = 0;
	for(int i = K - 1; i < R - (K - 1); i++){
		for(int j = K - 1; j < C - (K - 1); j++){
			int ok = 1;
			for(int k = i - (K - 1); k <= i + (K - 1); k++){
#define ABS(x) ((x) > 0 ? (x) : -(x))
				if(data[k][j] < K - ABS(k - i)){
					//printf("[%d %d %d]", i, j, k);
					ok = 0;
					break;
				}
			}
			if(ok) count++;
		}
	}

	printf("%d\n", count);
	return 0;
}
