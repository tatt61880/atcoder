#include <iostream>
using namespace std;
int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;
	cout << (C / ((A < B) ? A : B)) << endl;
	return 0;
}
