#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define For(i, m, n) for(int i = m; i < (int)(n); ++i)
int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	For(n, 1, 128){
		if(n % 3 == a && n % 5 == b && n % 7 == c){
			PrintLn(n);
		}
	}
	return 0;
}
