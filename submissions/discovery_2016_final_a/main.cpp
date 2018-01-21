#include <iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
int main(void)
{
	int n;
	cin >> n;
	int r, rank[100];
	rep(i, n) cin >> r, rank[r - 1] = i;
	int prise[100] = {100000, 50000, 30000, 20000, 10000, 0};
	rep(i, n) cout << prise[rank[i]] << endl;
	return 0;
}
