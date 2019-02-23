#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define Rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PrintLn(X) cout << X << endl
int main(void)
{
	int x, a, b;
	cin >> x >> a >> b;
	if(b <= a){
		PrintLn("delicious");
	}else if(b <= a
 + x){
		PrintLn("safe");
	}else{
		PrintLn("dangerous");
	}
	return 0;
}
