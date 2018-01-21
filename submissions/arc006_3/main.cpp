#include <iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main(void)
{
	int N;
	cin >> N;
	int w[100000];
	rep(n, N) cin >> w[n];
	int ans = 0;
	int top[100000];
	rep(n, N){
		bool f = false;
		rep(i, ans){
			if(w[n] <= top[i]){
				f = true;
				top[i] = w[n];
				break;
			}
		}
		if(!f) top[ans++] = w[n];
	}
	cout << ans << endl;
}
