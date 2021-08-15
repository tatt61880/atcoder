#include <iostream>
#include <algorithm>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (n); i++)

int main(void)
{
	while(1){
		int n, k;
		cin >> n >> k;
		if(n == 0) return 0;
		int x[1000];
		Rep(i, n) cin >> x[i];
		sort(x, x + n);
		int ans = 0;
		Rep(i, k) ans += x[i];
		PrintLn(ans);
	}
	return 0;
}
