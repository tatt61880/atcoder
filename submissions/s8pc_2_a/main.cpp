#include <iostream>
#include <string>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	string S;
	cin >> S;
	string str;
	Rep(i, S.size()){
		if((str.size() == 0 && S[i] == 'I') || (str.size() != 0 && str[str.size() - 1] != S[i])){
			str += S[i];
		}
	}
	if(str.size() == 0){
		PrintLn(0);
		return 0;
	}
	if(str[str.size() - 1] == 'I'){
		PrintLn(str.size());
	}else{
		PrintLn(str.size() - 1);
	}
	return 0;
}
