#include <iostream>
using namespace std;
typedef long long LL;

#define PrintLn(X) cout << X << endl

int f(LL x){
	int ret = 0;
	while(x) ret += x % 10, x /= 10;
	return ret;
}

int main(void)
{
	LL N;
	cin >> N;
	int num = 0;
	LL ans[200];
	for(LL x = N; x >= N - 18 * 9 && x > 0; x--){
		if(x + f(x) == N)
 ans[num++] = x;
	}
	PrintLn(num);
	for(int i = 0; i < num; i++) PrintLn(ans[num - 1 - i]);
	

	return 0;
}
