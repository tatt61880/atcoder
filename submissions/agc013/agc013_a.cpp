#include <iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

bool up, down;
int main(void)
{
	int N;
	cin >> N;

	int a, b;
	cin >> a;

	int ans = 1;
	rep(i, N - 1){
		cin >> b;
		if(a < b) up = true;
		if(a > b) down = true;
		if(up && down){
			up = down = false;
			ans++;
		}
		a = b;
	}
	cout << ans << endl;
	return 0;
}
