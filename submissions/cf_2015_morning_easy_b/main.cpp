#include <iostream>
#include <string>
using namespace std;
#define PrintLn(X) cout << (X) << endl
#define Rep(i, n) for(int i = 0; i < (n); i++)

int main(void)
{
	int N;
	cin >> N;
	string S;
	cin >> S;
	if(N % 2){
		PrintLn("-1");
		return 0;
	}
	int ans = 0;
	N /= 2;
	Rep(i, N){
		if(S[i] != S[N + i]) ans++;
	}
	PrintLn(ans);
	return 0;
}
