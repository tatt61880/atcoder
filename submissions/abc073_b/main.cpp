#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	int N;
	cin >> N;
	int ans = 0;
	Rep(i, N){
		int l, r;
		cin >> l >> r;
		ans += r - l + 1;
	}
	PrintLn(ans);
	return 0;
}
