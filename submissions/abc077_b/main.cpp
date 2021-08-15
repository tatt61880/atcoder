#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define PrintLn(X) cout << X << endl
int main(void)
{
	int N;
	cin >> N;
	PrintLn(((int)sqrt(N) * (int)sqrt(N)));
	return 0;
}
