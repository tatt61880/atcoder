#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main(void)
{
	int N, M;
	cin >> N >> M;
	int A[100000];
	int B[100000];
	rep(i, N) cin >> A[i];
	rep(i, M) cin >> B[i];
	sort(A, A+N);
	sort(B, B+M);
	int n = 0;
	rep(m, M){
		for(; n <= N; n++){
			if(n == N){
				cout << "NO" << endl;
				return 0;
			}
			if(B[m] <= A[n]){
				n++;
				break;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}
