#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define Print(X) cout << X
#define PrintLn(X) cout << X << endl

#define Rep(i, n) for(int i = 0; i < (int)n; ++i)
#define For(i, a, b) for(int i = a; i < (int)b; ++i)

int main(void)
{
	int y, m, d;
	scanf("%d/
%d/%d", &y, &m, &d);
	int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	while(1){
		if(m == 2 && d == 29 && !(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))){
		}else if(y / m / d * m * d == y){
			printf("%d/%02d/%02d\n", y, m, d);
			return 0;
		}
		d++;
		if(d > days[m - 1]){
			d = 1;
			m++;
		}
		if(m == 13){
			m = 1;
			y++;
		}
	}
	return 0;
}
