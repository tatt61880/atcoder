#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define Rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PrintLn(X) cout << X << endl
int main(void)
{
	int a, b;
	cin >> a >> b;
	if(a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0){

		PrintLn("Possible");
	}else{
		PrintLn("Impossible");
	}
	return 0;
}
