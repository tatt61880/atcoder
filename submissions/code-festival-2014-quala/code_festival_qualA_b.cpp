#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string A;
	cin >> A;
	int B;
	cin >> B;
	cout << A[(B - 1)%(A.size())] << endl;
	return 0;
}
