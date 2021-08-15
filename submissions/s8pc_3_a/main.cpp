#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int n, k;
	cin >> n >> k;
	n -= 2;

	int ans = 0;
	Rep(i, 77){
		Rep(j, 5){
			int sum = 0;
			sum += (i * 7 + j + 1);
			sum += (i * 7 + j + 2);
			sum += (i * 7 + j + 3);
			sum += ((i + 1) * 7 + j + 1);
			sum += ((i + 1) * 7 + j + 2);
			sum += ((i + 1) * 7 + j + 3);
			sum += ((i + 2) * 7 + j + 1);
			sum += ((i + 2) * 7 + j + 2);
			sum += ((i + 2) * 7 + j + 3);
			if(sum % 11 == k){
				ans++;
			}
		}
	}
	ans *= n / 77;

	Rep(i, n % 77){
		Rep(j, 5){
			int sum = 0;
			sum += (i * 7 + j + 1);
			sum += (i * 7 + j + 2);
			sum += (i * 7 + j + 3);
			sum += ((i + 1) * 7 + j + 1);
			sum += ((i + 1) * 7 + j + 2);
			sum += ((i + 1) * 7 + j + 3);
			sum += ((i + 2) * 7 + j + 1);
			sum += ((i + 2) * 7 + j + 2);
			sum += ((i + 2) * 7 + j + 3);
			if(sum % 11 == k){
				ans++;
			}
		}
	}
	PrintLn(ans);
	return 0;
}
