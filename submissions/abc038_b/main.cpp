#include <iostream>
using namespace std;

int main(void)
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	cout << ((C == A || C == B || D == A || D == B) ? "YES" : "NO") << endl;
	return 0;
}
