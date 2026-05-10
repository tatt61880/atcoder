#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define PrintLn(X) cout << X << endl
int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;
	cout << ((A <= C && C <= B) ? "Yes" : "No") << endl;
	return 0;
}
