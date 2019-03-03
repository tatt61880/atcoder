#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string S;
	cin >> S;
	cout << ((S[S.length() - 1] == 'T') ? "YES" : "NO") << endl;
	return 0;
}
