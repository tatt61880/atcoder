#include <stdio.h>

int main(void)
{
	int N, T;
	scanf("%d%d", &N, &T);
	int sum = 0;
	
	int last;
	for(int i = 0; i < N; i++){
		int A;
		scanf("%d", &A);
		if(i != 0){
			if(A - last >= T){
				sum += T;
			}else{
				sum += A - last;
			}
		}

		last = A;
	}
	sum += T;

	printf("%d\n", sum);
	return 0;
}
