#include <iostream>
#include <algorithm>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define PrintLn(x) cout << x << endl;
typedef long long LL;

int main(void)
{
	int N;
	cin >> N;
	LL A[100000];
	Rep(i, N) cin >> A[i];
	sort(A, A+N);
	LL sum = 0;
	Rep(i, N) sum += A[i];
	sum += A[N - 1];
	sum += N;
	PrintLn(sum);
	return 0;
}
//xx1xx1xxx1xxx
