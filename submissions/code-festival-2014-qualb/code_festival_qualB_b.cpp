#include <iostream>
using namespace std;
int main(void)
{
	int N, K;
	cin >> N >> K;
	int sum = 0;
	for(int i = 1; i <= N; i++){
		int a;
		cin >> a;
		sum += a;
		if(sum >= K){
			cout << i << endl;
			break;
		}
	}
	return 0;
}
