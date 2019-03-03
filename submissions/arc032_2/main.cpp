#include <iostream>
#include <vector>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define PrintLn(X) cout << X << endl
	
vector<int> v[100000];
int f[100000] = {0};
void connected(int n){
	f[n] = 1;
	for(auto& x: v[n]){
		if(f[x] == 1) continue;
		connected(x);
	}
}
int main(void)
{
	int N, M;
	cin >> N >> M;
	Rep(i, M){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int ans = -1;
	Rep(i, N){
		if(f[i] == 0){
			ans++;
			connected(i);
		}
	}
	PrintLn(ans);
	return 0;
}
