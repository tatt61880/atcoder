#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	string str1;
	string str2;
	while(n){
		string x = to_string(n % 2);
		n /= 2;
		str1 = x + str1;
		str2 = str2 + x;
	}
	if(str1 == str2){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}
