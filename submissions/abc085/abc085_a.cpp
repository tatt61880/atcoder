#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define printLn(X) cout << X << endl
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(){
	string S;
	cin >> S;
	S[3] = '8';
	printLn(S);
	return 0;
}
