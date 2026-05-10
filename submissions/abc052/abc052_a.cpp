#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	if(A * B > C * D){
		PrintLn(A*B);
	}else{
		PrintLn(C*D);
	}
	return 0;
}
