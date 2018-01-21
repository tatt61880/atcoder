#include <iostream>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define PrintLn(X) cout << (X) << endl
int main(void)
{
	int n;
	cin >> n;
	n--;
	n %= 40;
	if(n < 20){
		PrintLn(n + 1);
	}else{
		PrintLn(40 - n);
	}
	return 0;
}
