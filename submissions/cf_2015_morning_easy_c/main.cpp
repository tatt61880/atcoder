#include <iostream>
#include <algorithm>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (n); i++)
typedef long long LL;
int main(void)
{
	LL N, K, M, R;
	cin >> N >> K >> M >> R;
	LL P[100];
	Rep(i, N - 1) cin >> P[i];
	P[N - 1] = 0;
	sort(P, P + N);
	reverse(P, P + N);
	LL sum = 0;
	Rep(i, K) sum += P[i];
	if(sum >= K * R){
		PrintLn(0);
		return 0;
	}
	LL num = K * R - (sum - P[K - 1]);
	if(num > M){
		PrintLn(-1);
	}else{
		PrintLn(num);
	}
	return 0;
}
