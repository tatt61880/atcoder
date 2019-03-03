#include <iostream>
#include <string>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define PrintLn(X) cout << X << endl
int main(){
	int N, X;
	string s;
	cin >> N >> X;
	cin >> s;
	int ans = 0;
	Rep(i, N){
		int t;
		cin >> t;
		if(s[i] == '0'){
			ans += t;
		}else{
			if(X <= t){
				ans+=X;
			}else{
				ans+=t;
			}
		}
	}
	PrintLn(ans);
	return 0;
}
