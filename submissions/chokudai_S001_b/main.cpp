#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

ll a[100000];
int main(void)
{
	int N;
	cin >> N;
	Rep(i, N){
		cin >> a[i];
	}

	ll ans = 0;
	Rep(i, N){
		ans += a[i];
	}
	PrintLn(ans);
	return 0;
}
