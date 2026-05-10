#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

typedef long long ll;
ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(void)
{
	int N;
	ll Z;
	cin >> N >> Z;

	ll LCM = 1;
	Rep(i, N){
		ll a;
		cin >> a;
		ll GCD = gcd(a, Z);
		LCM = lcm(LCM, GCD);
	}
	PrintLn(LCM);
	return 0;
}
