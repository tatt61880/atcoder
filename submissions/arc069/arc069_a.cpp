#include <iostream>
using namespace std;

typedef long long ll;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

ll N, M;

ll f(ll n)
{
	ll s_needed = n - N;
	ll c_needed = 2 * n;
	if(s_needed < 0) s_needed = 0;
	return M >= s_needed * 2 + c_needed;
}

int main(void)
{
	cin >> N >> M;
	ll mn = 0;
	ll md;
	ll mx = 1000000000000;
	while(mn < mx - 1){
		md = (mn + mx) / 2;
		if(f(md)){
			mn = md;
		}else{
			mx = md;
		}
	}
	PrintLn(mn);
	return 0;
}
