#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *x, const void *y){
	return *(char *)x - *(char *)y;
}

int main(void)
{
	int N, K;
	scanf("%d%d", &N, &K);
	char S[1000];
	scanf("%s", S);

	char ans[1000];
	strcpy(ans, S);
	int err = 0; // ansの確定部分までにおける、不一致の文字数。
	for(int i = 0; i < N; i++){ //先頭から順番に確定させていく。
		char buf[1000];
		strcpy(buf, &ans[i]);
		int buf_len = strlen(buf);
		qsort((void *)buf, buf_len, sizeof(char), compare); //bufは未確定部分をソートした文字列になる。
		for(int j = 0; j < buf_len; j++){
			int count = err;
			int c = buf[j];
			if(S[i] != buf[j]){
				count++;
			}

			bool used[1000] = {0};
			used[j] = 1;
			// とりあえず、i + 1文字目以降すべて不一致とする。
			count += N - i - 1;
			// 不一致数をどれだけ減らせるか。
			for(int k = i + 1; k < N; k++){
				for(int l = 0; l < buf_len; l++){
					if(used[l] == 0 && S[k] == buf[l]){
						count--;
						used[l] = 1;
						break;
					}
				}
			}
			if(count <= K){ //この条件を満たすjは必ず存在する。条件を満たすのが早い方が辞書順で早い。
				int t = 0;
				for(t = i; t < N; t++){
					if(ans[t] == c) break;
				}
				ans[t] = ans[i];
				ans[i] = c;
				if(ans[i] != S[i]) err++;
				break;
			}
		}
		//printf("ans = %s\n", ans);
	}
	printf("%s\n", ans);

	return 0;
}
