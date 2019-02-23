#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i &lt
; (int)(b); ++i)

int main(void)
{
	int N, K;
	int A[100000];
	ll ans = 0;

	cin >> N >> K;
	Rep(i, N) cin >> A[i];
	sort(A, A + N);
	Rep(i, K){
		ans += A[i];
	}
	ans += (ll)K * (K - 1) / 2;
	PrintLn(ans);
	return 0;
}
