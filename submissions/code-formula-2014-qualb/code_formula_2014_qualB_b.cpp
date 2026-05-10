#include <iostream>
#include <string>
using namespace std;
#define PrintLn(X) cout << X << endl

int main(void)
{
	string s;
	cin >> s;
	int a = 0;
	int b = 0;
	for(int i = 0; i < s.size(); i++){
		if(i % 2 == s.size() % 2){
			a += s[i] - '0';
		}else{
			b += s[i] - '0';
		}
	}
	cout << a << " " << b << endl;
	return 0;
}
