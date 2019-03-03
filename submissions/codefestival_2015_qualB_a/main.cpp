#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str = "";
	for(int i = 0; i < 26; i++) str += ('a' + i);
	cout << str << str << endl;
	return 0;
}
