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
	ll N, A, B;
	cin >> N >> A >> B;
	ll ans = 0;
	ll x1;
	cin >> x1;
	Rep(i, N - 1){
		ll x2;
		cin >> x2;
		ll x = x2 - x1;
		if(x * A < B){
			ans += x * A;
		}else{
			ans += B;
		}
		x1 = x2;
	}
	PrintLn(ans);
	return 0;
}
