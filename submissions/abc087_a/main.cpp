#include <iostream>
using namespace std;

int main(void){
	int X, A, B;
	cin >> X >> A >> B;
	int ans = (X - A);
	ans -= (ans / B) * B;
	cout << ans << endl;
	return 0;
}
