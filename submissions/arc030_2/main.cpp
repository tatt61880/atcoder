#include <iostream>
#include <map>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int n, x;
	cin >> n >> x;
	x--;
	int h[100];
	map<int, int> mp[100];
	Rep(i, n) cin >> h[i];
	Rep(i, n-1){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		mp[a][b] = 1;
		mp[b][a] = 1;
	}
	int ans = 0;
	while(mp[x].size() != 0){
		Rep(i, n){
			if(i == x) continue;
			if(mp[i].size() != 1) continue;
			int y = mp[i].begin()->first;
			if(h[i]) {
				h[y] = 1;
				ans += 2;
			}
			mp[i].erase(y);
			mp[y].erase(i);
		}
	}
	PrintLn(ans);
	return 0;
}
