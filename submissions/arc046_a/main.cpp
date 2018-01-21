#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	char buf[1000];
	char *p;
	int num = 0;
	for(int i = 0; i < n; i++){
		while(1){
a:
			num++;
			sprintf(buf, "%d", num);
			p = buf;
			while(*p){
				if(*p != buf[0]){
					goto a;
				}
				p++;
			}
			break;
		}
	}
	printf("%d\n", num);
	return 0;
}
