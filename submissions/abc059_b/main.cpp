#include <iostream>
#include <cstring>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	char a[101];
	char b[101];
	cin >> a >> b;
	if(strlen(a) > strlen(b)){
		PrintLn("GREATER");
		return 0;
	}
	if(strlen(a) < strlen(b)){
		PrintLn("LESS");
		return 0;
	}
	Rep(i, strlen(a)){
		if(a[i] > b[i]){
			PrintLn("GREATER");
			return 0;
		}
		if(a[i] < b[i]){
			PrintLn("LESS");
			return 0;
		}
	}
	PrintLn("EQUAL");
	return 0;
}
