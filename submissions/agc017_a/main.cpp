#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

ull comb(int n, int r)
{
	ull ret = 1;
	int x[50];
	Rep(i, r){
		x[i] = i + 1;
	}
	for(int i = n; i > (n - r); i--){
		ret *= i;
		Re
p(j, r){
			if(x[j] && ret % x[j] == 0){
				ret /= x[j];
				x[j] = 0;
			}
		}
	}
	return ret;
}

int main(void)
{
	int N, P;
	cin >> N >> P;

	int odd = 0;
	int even = 0;
	Rep(i, N){
		int a;
		cin >> a;
		if(a % 2){
			odd++;
		}else{
			even++;
		}
	}

	ull ans = 1;
	Rep(i, even) ans *= 2;

	ull ans2 = 0;
	for(int i = 0; i <= odd; i++){
		if((i % 2) == P){
			ans2 += comb(odd, i);
		}
	}

	printf("%llu\n", (ull)ans * ans2);
	return 0;
}
