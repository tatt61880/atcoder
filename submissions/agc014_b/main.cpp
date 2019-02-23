#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int x[100000] = {0};
int main(void)
{
	int N, M;
	cin >> N >> M;
	Rep(i, M){
		int a, b;
		cin >> a >> b;
		x[a - 1]
++;
		x[b - 1]++;
	}
	Rep(i, N){
		if(x[i] % 2){
			PrintLn("NO");
			return 0;
		}
	}
	PrintLn("YES");
	return 0;
}
