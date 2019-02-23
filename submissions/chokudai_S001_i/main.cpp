#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll MOD = 1000000007;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

ll a[100000];
ll b[100000];
int main(void)
{
	int N;
	cin >> N;
	Rep(i, N){
		cin >> a[i];
	}

	b[0] = 0;
	For(i, 1,
 N + 1){
		b[i] = b[i - 1] + a[i - 1];
	}

	ll ans = 0;
	int l = 0;
	int r = 1;
	while(1){
		if(b[r] - b[l] < N){
			r++;
		}else if(b[r] - b[l] > N){
			l++;
		}else{
			ans++;
			l++;
			r++;
		}
		if(r == N + 1) break;
	}
	PrintLn(ans);
	return 0;
}
