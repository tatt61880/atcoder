#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int main(void)
{
	int N, x;
	cin >> N >> x;
	int A[100000];
	ll ans = 0;
	cin >> A[0];
	Rep(i, N - 1){
		cin >> A[i + 1];
		int extra = A[i] + A[i + 1] - x;
		if(extra > 0){
			if(A[i + 1] >= extra){
				A[i + 1] -= extra;
				ans += extra;
			}else{
				A[i + 1] = 0;
				ans += extra;
			}
		}
	}
	PrintLn(ans);
	return 0;
}
