#include <iostream>
#include <vector>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define PrintLn(X) cout << X << endl
	
vector<int> v[100];
int f[100] = {0};
int connected(int n, int exception){
	f[n] = 1;
	int loop = 0;
	for(auto& x: v[n]){
		if(f[x] == 1) {
			if(x != exception) loop++;
			continue;
		}
		loop += connected(x, n);
	}
	return loop;
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
	int ans = 0;
	Rep(i, N){
		if(f[i] == 0){
			if(connected(i, -1) == 0) ans++;
		}
	}
	PrintLn(ans);
	return 0;
}
