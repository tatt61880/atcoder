#include <cstdio>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
int main(void)
{
	char c[10][11];
	rep(h, 10) scanf("%s", &c[h][0]);
	rep(w, 10){
		int sum = 0;
		rep(h, 10){
			sum += c[h][w];
		}
		if(sum == 'x' * 10){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}
