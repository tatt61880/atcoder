#include <iostream>
#include <string>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (n); i++)
int main(void)
{
	int N;
	cin >> N;
	Rep(i, N){
		string str;
		cin >> str;
		switch(str[0]){
			case 'B': cin >> str; cin >> str; cout << str[0]; break;
			case 'M': cin >> str; cin >> str; cout << str[str.size() / 2]; break;
			case 'E': cin >> str; cin >> str; cout << str[str.size() - 1]; break;
		}
	}
	cout << endl;
	return 0;
}
