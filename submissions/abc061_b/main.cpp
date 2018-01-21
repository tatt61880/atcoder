#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PrintLn(X) cout << X << endl
int main(void)
{
	int N, M;
	cin >> N >> M;
	int ans[50] = {0};
	Rep(i, M){
		int a, b;
		cin >> a >> b;
		a--; b--;
		ans[a]++;
		ans[b]++;
	}
	Rep(i, N){
		PrintLn(ans[i]);
	}
	return 0;
}
