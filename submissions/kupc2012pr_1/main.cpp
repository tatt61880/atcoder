#include <iostream>
using namespace std;
#define PrintLn(X) cout << (X) << endl
#define Rep(i, n) for(int i = 0; i < (n); i++)
typedef long long LL;
LL A(int m, int n){
	if(m == 0) return n + 1;
	if(m == 1) return n + 2;
	if(m == 2) return 2*n + 3;
	LL ret = 8;
	Rep(i, n) ret *= 2;
	return ret - 3;
}
int main(void)
{
	LL m, n;
	cin >> m >> n;
	PrintLn(A(m, n));
	return 0;
}
