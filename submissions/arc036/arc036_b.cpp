#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int N;
	cin >> N;
	int h[300000];
	Rep(i, N) cin >> h[i];
	int s = 0;
	int ans = 0;
	Rep(i, N){
		if(i == 0 || i == N - 1 || h[i - 1] > h[i] && h[i] < h[i + 1]){
			ans = max(ans, i - s + 1);
			s = i;
		}
	}
	PrintLn(ans);
	return 0;
}

