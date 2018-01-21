#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(void)
{
	int n;
	cin >> n;
	int ans=0;
	rep(i, n){
		int s=0;
		rep(j, 5){
			int a;
			cin >> a;
			s+=a;
		}
		if(s<20) ans++;
	}
	cout << ans << endl;
	return 0;
}
