#include <iostream>
#include <string>
using namespace std;
#define println(x) cout << (x) << endl
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	string s;
	cin >> s;
	int ans = 0;
	rep(i, s.size()){
		if(i % 2 == 0){
			ans += (s[i] - '0');
		}else{
			ans -= (s[i] - '0');
		}
	}
	println(ans);
	return 0;
}
