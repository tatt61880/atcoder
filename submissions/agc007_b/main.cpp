#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int p[20000];
int a[20000];
int b[20000];
int main(void)
{
	int N;
	cin >> N;
	Rep(i, N) cin >> p[i];
	Rep(i, N){
		a[i] = 1 + 30000 * i;
		b[i] = 1000000000 - 30000 * i;
	}
	Rep(i, N){
		a[p[i] - 1] += i;
	}
	Rep(i, N - 1) cout << a[i] << " ";
	cout << a[N - 1] << endl;
	Rep(i, N - 1) cout << b[i] << " ";
	cout << b[N - 1] << endl;
	return 0;
}
