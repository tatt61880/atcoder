#include <iostream>
#include <string>
using namespace std;

int main(void){
	string s;
	cin >> s;
	int ans = 0;
	ans += s[0] == '1';
	ans += s[1] == '1';
	ans += s[2] == '1';
	cout << ans << endl;
	return 0;
}
