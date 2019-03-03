#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#define PrintLn(X) cout << X << endl
void invalid(void)
{
	PrintLn("invalid");
	exit(0);
}
int main(void)
{
	string str;
	cin >> str;
	if(str.size() != 5) invalid();
	cin >> str;
	if(str.size() != 7) invalid();
	cin >> str;
	if(str.size() != 5) invalid();
	PrintLn("valid");
	return 0;
}
