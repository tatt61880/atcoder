#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (n); i++)
int main(void)
{
	int N, T, E;
	cin >> N >> T >> E;
	Rep(i, N){
		int a;
		cin >> a;
		int t = (T + E) / a * a;
		if(T - E <= t && t <= T + E){
			PrintLn(i + 1);
			return 0;
		}
	}
	PrintLn(-1);
	return 0;
}
