#include <iostream>
using namespace std;

typedef long long ll;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

const ll md = 1000000007LL;
ll dp[3][3][52];

enum{
	r,
	g,
	b
};

int main(void)
{
	int N;
	cin >> N;

	char data[2][53];
	cin >> data[0];
	cin >> data[1];

	Rep(i, N){
		if(i == 0){
			if(data[0][0] == data[1][0]){
				dp[r][r][0] = 1;
				dp[g][g][0] = 1;
				dp[b][b][0] = 1;
			}else{
				dp[r][g][0] = 1;
				dp[g][b][0] = 1;
				dp[b][r][0] = 1;
				dp[r][b][0] = 1;
				dp[g][r][0] = 1;
				dp[b][g][0] = 1;
			}
		}else{
			if(data[0][i] == data[1][i]){
				dp[r][r][i] = dp[g][b][i-1] + dp[b][g][i-1] + dp[g][g][i-1] + dp[b][b][i-1];
				dp[g][g][i] = dp[r][b][i-1] + dp[b][r][i-1] + dp[b][b][i-1] + dp[r][r][i-1];
				dp[b][b][i] = dp[g][r][i-1] + dp[r][g][i-1] + dp[r][r][i-1] + dp[g][g][i-1];
			}else{
				if(data[0][i] == data[0][i - 1]){
					dp[r][g][i] = dp[r][g][i-1];
					dp[g][b][i] = dp[g][b][i-1];
					dp[b][r][i] = dp[b][r][i-1];
					dp[r][b][i] = dp[r][b][i-1];
					dp[g][r][i] = dp[g][r][i-1];
					dp[b][g][i] = dp[b][g][i-1];
				}else{
					dp[r][g][i] = dp[b][b][i-1] + dp[b][r][i-1] + dp[g][b][i-1] + dp[g][r][i-1];
					dp[g][b][i] = dp[r][r][i-1] + dp[r][g][i-1] + dp[b][r][i-1] + dp[b][g][i-1];
					dp[b][r][i] = dp[g][g][i-1] + dp[g][b][i-1] + dp[r][g][i-1] + dp[r][b][i-1];
					dp[r][b][i] = dp[g][g][i-1] + dp[g][r][i-1] + dp[b][g][i-1] + dp[b][r][i-1];
					dp[g][r][i] = dp[b][b][i-1] + dp[b][g][i-1] + dp[r][b][i-1] + dp[r][g][i-1];
					dp[b][g][i] = dp[r][r][i-1] + dp[r][b][i-1] + dp[g][r][i-1] + dp[g][b][i-1];
				}
			}
		}
		dp[r][r][i] %= md;
		dp[g][g][i] %= md;
		dp[b][b][i] %= md;
		dp[r][g][i] %= md;
		dp[g][b][i] %= md;
		dp[b][r][i] %= md;
		dp[r][b][i] %= md;
		dp[g][r][i] %= md;
		dp[b][g][i] %= md;
	}
	ll ans = 0;
	ans += dp[r][r][N - 1]; ans %= md;
	ans += dp[g][g][N - 1]; ans %= md;
	ans += dp[b][b][N - 1]; ans %= md;
	ans += dp[r][g][N - 1]; ans %= md;
	ans += dp[g][b][N - 1]; ans %= md;
	ans += dp[b][r][N - 1]; ans %= md;
	ans += dp[r][b][N - 1]; ans %= md;
	ans += dp[g][r][N - 1]; ans %= md;
	ans += dp[b][g][N - 1]; ans %= md;

#if 0
	PrintLn(dp[r][r][N - 1]);
	PrintLn(dp[g][g][N - 1]);
	PrintLn(dp[b][b][N - 1]);
	PrintLn(dp[r][g][N - 1]);
	PrintLn(dp[g][b][N - 1]);
	PrintLn(dp[b][r][N - 1]);
	PrintLn(dp[r][b][N - 1]);
	PrintLn(dp[g][r][N - 1]);
	PrintLn(dp[b][g][N - 1]);
#endif
	PrintLn(ans);
	return 0;
}
