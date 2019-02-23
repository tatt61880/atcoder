#include <iostream>
using namespace std;
#define PrintLn(X) cout << (X) << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int N;
	cin >> N;
	int ans = 0;
	Rep(i, 9){
		static int d = 1;
		ans += (N / d + 8) / 10 * d;
		if((N / d) % 10 == 1) ans += N % d + 1;
		d *= 10;

	}
	PrintLn(ans);
	return 0;
}
