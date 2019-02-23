#include <iostream>
using namespace std;

typedef long long ll;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	int N;
	cin >> N;
	int num[1000] = {0};
	For(i, 1, N + 1){
		int n = i
;
		while(n != 1){
			for(int j = 2; j <= n; j++){
				if(n % j == 0){
					num[j]++;
					n /= j;
					break;
				}
			}
		}
	}
	ll ans = 1;
	Rep(i, 999){
		ans *= (num[i] + 1);
		ans %= 1000000007;
	}
	PrintLn(ans);
	return 0;
}
