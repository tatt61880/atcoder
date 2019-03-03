#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
ll a[100000];
int main(void)
{
	int N;
	cin >> N;
	Rep(i, N){
		cin >> a[i];
	}
	sort(a, a + N);
	Rep(i, N){
		cout << a[i];
		if(i != N - 1){
			cout << ' ';
		}
	}
	cout << endl;
	return 0;
}
