#include <iostream>
#include <string>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (n); i++)
int main(void)
{
	string s;
	cin >> s;
	int count[10] = {0};
	count[s[0] - '0']++;
	count[s[1] - '0']++;
	count[s[2] - '0']++;
	count[s[3] - '0']++;
	count[s[5] - '0']--;
	count[s[6] - '0']--;
	count[s[8] - '0']--;
	count[s[9] - '0']--;
	Rep(i, 10){
		if(count[i] != 0){
			PrintLn("no");
			return 0;
		}
	}
	PrintLn("yes");
	return 0;
}
