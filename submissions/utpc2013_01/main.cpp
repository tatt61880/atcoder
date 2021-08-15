#include <iostream>
#include <string>
using namespace std;
#define PrintLn(X) cout << (X) << endl

int main(void)
{
	char s[4];
	cin >> s;
	bool f = true;
	if(string("CEFGHIJKLMNSTUVWXYZ").find(s[0]) == -1) f = false;
	if(string("CEFGHIJKLMNSTUVWXYZ").find(s[1]) == -1) f = false;
	if(string("ADOPQR").find(s[2]) == -1) f = false;
	if(string("CEFGHIJKLMNSTUVWXYZ").find(s[3]) == -1) f = false;
	PrintLn(f ? "yes" : "no");
	return 0;
}
