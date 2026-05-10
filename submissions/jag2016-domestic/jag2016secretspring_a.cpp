#include <iostream>
#include <string>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (n); i++)

int main(void)
{
	int n;
	cin >> n;
	int count = 0;
	Rep(i, n){
		string s;
		cin >> s;
		if(s[0] == 'A'){
			count++;
		}else{
			count--;
			if(count < 0){
				PrintLn("NO");
				return 0;
			}
		}
	}
	if(count == 0){
		PrintLn("YES");
	}else{
		PrintLn("NO");
	}
	return 0;
}
