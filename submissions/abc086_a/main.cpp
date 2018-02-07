#include <iostream>
#include <string>
using namespace std;

int main(void){
	int A, B;
	cin >> A >> B;
	string ans = (((A * B) % 2) == 0) ? "Even" : "Odd";
	cout << ans << endl;
	return 0;
}
