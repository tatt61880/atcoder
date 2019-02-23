#include <iostream>
#include <string>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	string S;
	cin >> S;
	int T;
	cin >> T;
	int x = 0;
	int y = 0;
	int q = 0;
	Rep(i, S.size()){
		switch(S[i]){
			case 'L': x--
; break;
			case 'R': x++; break;
			case 'U': y++; break;
			case 'D': y--; break;
			case '?': q++; break;
		}
	}
	if(T == 1){
		PrintLn(abs(x) + abs(y) + q);
	}else{
		int m = abs(x) + abs(y) - q;
		if(m > 0){
			PrintLn(m);
		}else{
			PrintLn(abs(m) % 2);
		}
	}
	return 0;
}
