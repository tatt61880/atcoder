#include <iostream>
using namespace std;
int num(int n){
	int ret = (n / 400) * 97;
	for(int i = 0; i <= n % 400; i++){
		if(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) ret++;
	}
	return ret;
}
int main(void)
{
	int A, B;
	cin >> A >> B;
	cout << num(B) - num(A - 1) << endl;
	return 0;
}
