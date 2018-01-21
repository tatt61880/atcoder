#include <iostream>
#include <algorithm>
using namespace std;
#define Print(X) cout << X
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)n; ++i)
#define For(i, a, b) for(int i = a; i < (int)b; ++i)
int main(void)
{
	char c;
	cin >> c;
	if(c == 'O' || c == 'P'  || c == 'K'  || c == 'L'){
		PrintLn("Right");
	}else{
		PrintLn("Left");
	}
	return 0;
}
