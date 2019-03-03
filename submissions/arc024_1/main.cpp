#include <stdio.h>
int main(void)
{
	int L, R;
	scanf("%d%d", &L, &R);
	int lsize[100];
	for(int l = 0; l < L; l++){
		scanf("%d", &lsize[l]);
	}
	int rsize[100];
	for(int r = 0; r < R; r++){
		scanf("%d", &rsize[r]);
	}
	int count = 0;
	for(int l = 0; l < L; l++){
		for(int r = 0; r < R; r++){
			if(lsize[l] == rsize[r]){
				rsize[r] = 0;
				count++;
				break;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
