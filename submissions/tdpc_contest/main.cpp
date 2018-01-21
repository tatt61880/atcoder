#include <iostream>
using namespace std;
int main(void)
{
	int N;
	cin >> N;
	int A[10001] = {1};
	for(int i = 0; i < N; i++){
		int p;
		cin >> p;
		for(int j = 10000; j >= 0; j--){
			if(A[j]) A[j + p] = 1;
		}
	}
	int ans = 0;
	for(int j = 0; j <= 10000; j++){
		if(A[j]) ans++;
	}
	cout << ans << endl;
	return 0;
}
