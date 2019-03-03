#include <iostream>
using namespace std;
int main(void){
	int N, A, B;
	cin >> N >> A >> B;
	int ans = A * N;
	if(ans > B) ans = B;
	cout << ans << endl;
	return 0;
}
