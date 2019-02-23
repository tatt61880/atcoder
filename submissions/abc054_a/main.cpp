#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int main(void)
{
	int A, B;
	cin >> A >> B;
	if(A == B){
		PrintLn("Draw");
	}else if(A == 1 || (B != 1 && A > B)){
		PrintLn(&#34
;Alice");
	}else{
		PrintLn("Bob");
	}
	return 0;
}
