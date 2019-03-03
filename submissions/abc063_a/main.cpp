#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PrintLn(X) cout << X << endl
int main(void)
{
	int a, b;
	cin >> a >> b;
	if(a + b < 10){
		PrintLn(a + b);
	}else{
		PrintLn("error");
	}
	return 0;
}
