#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main(void)
{
	int N, T;
	cin >> N >> T;
	int A[100000];
	int C[100000];
	rep(i, N){
		int a, b;
		cin >> a >> b;
		A[i] = a;
		C[i] = a - b;
	}
	int sum = 0;
	rep(i, N) sum += A[i];
	int count = 0;
	sort(C, C+N);
	rep(i, N){
		if(sum <= T){
			break;
		}
		count++;
		sum -= C[N - 1 - i];
	}
	if(sum > T){
		cout << "-1" << endl;
	}else{
		cout << count << endl;
	}
	return 0;
}
