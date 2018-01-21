#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;
	int ans = 0;
	while(A % 2 == 0 && B % 2 == 0 && C % 2 == 0){
		if(A == B && B == C){
			PrintLn(-1);
			return 0;
		}
		int a = A / 2;
		int b = B / 2;
		int c = C / 2;
		A = b + c;
		B = c + a;
		C = a + b;
		ans++;
	}
	PrintLn(ans);
	return 0;
}
