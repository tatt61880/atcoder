#include <iostream>
#include <cstdlib>
using namespace std;

#define PrintLn(X) cout << X << endl
int main(void)
{
	int x, a, b;
	cin >> x >> a >> b;
	if(abs(x-a)<abs(x-b)){
		PrintLn("A");
	}else{
		PrintLn("B");
	}
	return 0;
}
