#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PrintLn(X) cout << X << endl
int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	if((10 * b + c) % 4 == 0){
		PrintLn("YES");
	}else{
		PrintLn("NO");
	}
	return 0;
}
