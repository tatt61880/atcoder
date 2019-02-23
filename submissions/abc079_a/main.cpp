#include <iostream>
using namespace std;

int main(void){
	int N;
	cin >> N;
	bool ans = ((N % 1000) % 111 == 0 || (N / 10) % 111 == 0);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
