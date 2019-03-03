#include <iostream>
using namespace std;
typedef long long ll;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	ll a, b, x;
	cin >> a >> b >> x;
	if(a == 0){
		PrintLn((b / x) + 1);
	}else{
		PrintLn((b / x) - ((a - 1) / x));
	}
	return 0;
}
