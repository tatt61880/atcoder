#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define Print(X) cout << X
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)n; ++i)
#define For(i, a, b) for(int i = a; i < (int)b; ++i)
int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	if(a <= b + c && b <= a + c && c <= a + b){
		printf("%.9f\n", 3.14159265358 * (a + b + c) * (a + b + c));
	}else if(c > a + b){
		printf("%.9f\n", 3.14159265358 * ((a + b + c) * (a + b + c) - (c - a - b) * (c - a - b)));
	}else if(b > a + c){
		printf("%.9f\n", 3.14159265358 * ((a + b + c) * (a + b + c) - (b - a - c) * (b - a - c)));
	}else{
		printf("%.9f\n", 3.14159265358 * ((a + b + c) * (a + b + c) - (a - b - c) * (a - b - c)));
	}
	return 0;
}
