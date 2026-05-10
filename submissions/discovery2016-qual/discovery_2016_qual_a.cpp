#include <stdio.h>
int main(void)
{
	char str[] = "DiscoPresentsDiscoveryChannelProgrammingContest2016";
	int W;
	scanf("%d", &W);

	printf("%c", str[0]);
	for(int i = 1; i < 51; i++){
		if(i % W == 0){
			printf("\n");
		}
		printf("%c", str[i]);
	}

	printf("\n");
	return 0;
}
