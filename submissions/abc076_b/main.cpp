#include <iostream>
#include <cstring>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	int N, K;
	cin >> N >> K;
	int ans = 1;
	Rep(i, N){
		if(ans * 2 < ans + K){
			ans *= 2;
		}else{
			ans += K;
		}
	}
	cout << (ans) << endl;
	return 0;
}
