#include <cstdio>
#define rep(i, n) for(int i = 0; i < (n); i++)

int main(void)
{
	int a,b,c,d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int e[10][10];
	rep(ic, c) rep(ia, a) scanf("%d", &e[ic][ia]);
	rep(i, 101){
		int point = 100 - i;
		int num = 0;
		rep(ic, c){
			int count = 0;
			rep(ia, a){
				if(e[ic][ia] >= point) count++;
			}
			if(count >= b) num++;
		}
		if(num >= d){
			printf("%d\n", poin
t);
			return 0;
		}
	}
}
