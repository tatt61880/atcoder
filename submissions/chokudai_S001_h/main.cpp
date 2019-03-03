#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll MOD = 1000000007;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i <= (int)(b); ++i)
int N;
ll a[100000];
int L[100000]; // LIS
ll ans = 0;
int LIS(void)
{
	int len;
	int k;
	int lo, hi, md;
	L[0] = a[0];
	len = 1;
	for(k = 1; k < N; k++){
		if(L[len-1] < a[k]){
			L[len++] = a[k];
			continue;
		}
		lo = 0;
		hi = len;
		while (lo < hi) {
			md = (lo + hi)/2;
			if (L[md] < a[k]) lo = md + 1;
			else               hi = md;
		}
		if (lo < len) L[lo] = a[k];
		else       L[len++] = a[k];
	}
	return len;
}
int main(void)
{
	cin >> N;
	Rep(i, N){
		cin >> a[i];
	}
	ans = LIS();
	PrintLn(ans);
	return 0;
}
