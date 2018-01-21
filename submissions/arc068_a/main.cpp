#include <iostream>
using namespace std;
typedef long long ll;
#define PrintLn(X) cout << X << endl
int main(void)
{
	ll N;
	cin >> N;
	ll ans = (N / 11) * 2;
	if(N % 11 == 0){
	}else if(N % 11 <= 6){
		ans += 1;
	}else{
		ans += 2;
	}
	PrintLn(ans);
	return 0;
}
