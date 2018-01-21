#include <cstdio>
int main(void)
{
	int N;
	scanf("%d", &N);
	if(N % 4 == 0){
		puts("GO");
	}else{
		puts("SEN");
	}
	return 0;
}
