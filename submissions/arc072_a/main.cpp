#include <iostream>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int n;
	cin >> n;

	ll sum[2] = {0};
	ll ans[2] = {0};

	rep(i, n){
		int a;
		cin >> a;

		rep(j, 2){
			sum[j] += a;
			if((i + j) % 2){
				if(sum[j] >= 0){
					ans[j] &
#43;= sum[j] + 1;
					sum[j] = -1;
				}
			}else{
				if(sum[j] <= 0){
					ans[j] += -sum[j] + 1;
					sum[j] = 1;
				}
			}
		}
	}

	cout << (ans[0] < ans[1] ? ans[0] : ans[1]) << endl;
	return 0;
}
