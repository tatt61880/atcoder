#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int n = sqrt(N);
	if(N == n * n){
		cout << 0 << endl;
	}else{
		n++;
		cout << (n*n - N) << endl;
	}
	return 0;
}
