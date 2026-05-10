#include <iostream>
using namespace std;
int main(void)
{
	int N;
	cin >> N;
	int sum = 0;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		sum *= 2;
		sum += a;
	}
	cout << sum << endl;
	return 0;
}
