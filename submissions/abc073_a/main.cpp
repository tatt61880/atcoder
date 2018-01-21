#include <iostream>
#include <string>
using namespace std;
#define PrintLn(X) cout << X << endl
int main(void)
{
	int a;
	cin >> a;
	if(a % 10 == 9 || a / 10 == 9){
		PrintLn("Yes");
	}else{
		PrintLn("No");
	}
	return 0;
}
