#include <iostream>
#include <string>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define PrintLn(X) cout << X << endl

int main(
){
	string s;
	int A, B;
	cin >> A >> B;
	cin >> s;
	if(A <= s.size() && s.size() <= B){
		PrintLn("YES");
	}else{
		PrintLn("NO");
	}
	return 0;
}
