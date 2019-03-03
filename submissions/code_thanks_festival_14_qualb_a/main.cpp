#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
int main(void)
{
	int A, B;
	cin >> A >> B;
	PrintLn((A > B ? A : B));
	return 0;
}
