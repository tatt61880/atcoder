#include <iostream>
#include <cstring>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	char O[51], E[51];
	cin >> O >> E;
	Rep(i, strlen(O)){
		cout << O[i];
		if(i != strlen(E)){
			cout << E[i];
		}
	}

	cout << endl;
	return 0;
}
