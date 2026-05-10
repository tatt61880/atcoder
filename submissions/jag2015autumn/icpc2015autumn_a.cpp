#include <iostream>
#include <string>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (n); i++)

string S;
string T;
bool f(int n){
	int count = 0;
	int t = 0;
	for(int s = n; s < S.size(); s += 2){
		count++;
		for(; t < T.size(); t++){
			if(S[s] == T[t]){
				count--;
				t++;
				break;
			}
		}
	}
	return count == 0;
}

int main(void)
{
	cin >> S;
	cin >> T;

	bool f1 = f(0);
	bool f2 = f(1);

	if(f1 || f2){
		PrintLn("Yes");
	}else{
		PrintLn("No");
	}
	return 0;
}
