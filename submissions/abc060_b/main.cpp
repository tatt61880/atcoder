#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define PrintLn(X) cout << X << endl
int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;

	int n = 0;
	while(1){
		if((A * n) % B == C){
			PrintLn("YES");
			return 0;
		}else if(n == B){
			PrintLn("NO");
			return 0;
		}
		n++;
	}
}
