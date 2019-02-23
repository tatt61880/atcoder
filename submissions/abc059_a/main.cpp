#include <iostream>
#include <cstring>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	Rep(i, 3){
		char s[11];
		cin >> s;
		cout << (char)(s[0] + 'A' - 'a');
	}
	cout << endl;
	return 0;

}
