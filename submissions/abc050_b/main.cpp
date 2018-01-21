#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int T[100];
int main(void)
{
	int N, M;
	cin >> N;
	int ans = 0;
	Rep(i, N){
		cin >> T[i];
		ans += T[i];
	}
	cin >> M;
	Rep(i, M){
		int p, x;
		cin >> p >> x;
		p--;
		PrintLn(ans + x - T[p]);
	}
}
