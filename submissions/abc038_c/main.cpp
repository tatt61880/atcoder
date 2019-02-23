#include <iostream>
using namespace std;
typedef long long ll;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int N;
	cin >> N;
	int a[100000];
	Rep(i, N) cin >> a[i];

	ll ans = 0;
	int count = 1;
	Rep(i, N - 1){
		if(a[i + 
1] <= a[i]){
			ans += (ll)count * (count + 1) / 2;
			count = 0;
		}
		count++;
	}
	ans += (ll)count * (count + 1) / 2;
	PrintLn(ans);
	return 0;
}
