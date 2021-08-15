#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	char S[100001];
	cin >> S;
	ll ans = 0;
	int len = strlen(S);
	Rep(i, len){
		if(S[i] == 'U'){
			ans += 1 * (len - i - 1);
			ans += 2 * (i);
		}else{
			ans += 2 * (len - i - 1);
			ans += 1 * (i);
		}
	}
	PrintLn(ans);
	return 0;
}
