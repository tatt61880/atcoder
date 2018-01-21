#include <iostream>
using namespace std;
int main(void)
{
	int N, M;
	cin >> N >> M;
	int A[100001] = {0};
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		A[a]++;
	}
	int ans = -1;
	for(int i = 0; i <= M; i++){
		if(A[i] > (N / 2)) {
			ans = i;
			break;
		}
	}
	if(ans == -1){
		cout << "?" << endl;
	}else{
		cout << ans << endl;
	}
	return 0;
}
