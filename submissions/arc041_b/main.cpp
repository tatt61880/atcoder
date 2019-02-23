#include <iostream>
using namespace std;
typedef long long LL;
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define PrintLn(X) cout << X << endl

int main(void)
{
	int N, M;
	cin >> N >> M;
	char b[500][500];
	Rep(i, N) Rep(j, M) cin >> b[i][j];
	char a[500][500];
	Rep(i, N) Rep(j, M) a[i][j] = &#39
;0';
	Rep(i, N) Rep(j, M){
		if(b[i][j] != '0'){
			a[i + 1][j] = b[i][j];
			b[i + 1][j - 1] -= b[i][j] - '0';
			b[i + 1][j + 1] -= b[i][j] - '0';
			b[i + 2][j] -= b[i][j] - '0';
			b[i][j] = '0';
		}
	}
	Rep(i, N){
		Rep(j, M) cout << a[i][j];
		cout << endl;
	}
	return 0;
}
