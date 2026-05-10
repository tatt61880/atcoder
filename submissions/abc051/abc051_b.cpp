#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int K, S;
	cin >> K >> S;
	int ans = 0;
	Rep(X, K + 1){
		Rep(Y, K + 1){
			int Z = S - X - Y;
			if(0 <= Z && Z <= K){
				ans++;
			}
		}
	}
	PrintLn(ans);
}
