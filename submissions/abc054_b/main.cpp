#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

char a[51][51];
char b[51][51];
int main(void)
{
	int N, M;
	cin >> N >> M;
	Rep(n, N) cin >> a[n];
	Rep(m, M) cin >> b[m];

	Rep(h, N - M + 1){
		Rep(w, N - M + 1){
			bool f = true;
			Rep(y, M){
				Rep(x, M){
					if(a[y + h][x + w] != b[y][x]){
						f = false;
						break;
					}
				}
			}
			if(f){
				PrintLn("Yes");
				return 0;
			}
		}
	}
	PrintLn("No");

	return 0;
}
