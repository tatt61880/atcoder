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
	int n;
	cin >> n;
	int sum = 0;
	int max = 0;
	Rep(i, n){
		int d;
		cin >> d;
		if(d > max) max = d;
		sum += d;
	}
	PrintLn(sum);
	if(max * 2 > sum){
		PrintLn(max - (sum - max));
	}else{
		PrintLn(0);
	}
	return 0;
}
