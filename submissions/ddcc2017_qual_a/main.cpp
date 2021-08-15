#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	char S[5];
	cin >> S;
	if(S[0] == S[1] && S[1] != S[2] && S[2] == S[3]){
		PrintLn("Yes");
	}else{
		PrintLn("No");
	}
	return 0;
}
