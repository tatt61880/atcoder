#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl

int main(void)
{
	char a, b, c;
	cin >> a >> b >> c;

	switch(c){
	case 'B': cout << "Bachelor "; break;
	case 'M': cout << "Master "; break;
	case 'D': cout << "Doctor "; break;
	}
	PrintLn(a << b);
	return 0;
}
