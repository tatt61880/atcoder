#include <iostream>
using namespace std;
typedef long long ll;
#define PrintLn(X) cout << X << endl

ll dp[500001][2];

int main(void)
{
	ll N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	N--;

	if(A > B) swap(A, B);
	B -= A;

	for(int i = 0; i <= N; i++){
		ll mn = C * N - i * (C + D);
		
ll mx = D * N - i * (C + D);
		if(mn <= B && B <= mx){
			PrintLn("YES");
			return 0;
		}
	}

	PrintLn("NO");
	return 0;
}
