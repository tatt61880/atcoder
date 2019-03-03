#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define PrintLn(X) cout << X << endl
int main(void)
{
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	if(a == b){
		PrintLn("YES");
	}else{
		PrintLn("NO");
	}
	return 0;
}
