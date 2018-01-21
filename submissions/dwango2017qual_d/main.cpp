#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int X[100000];
int Y[100000];
int selected[100000] = {0};
int diff[100000];
int dp[2] = {0}; // M - 1蛟九す繝｣繝ｪ繧呈ｮ九＠縺滄｣溘∋譁ｹ繧偵＠縺溷ｾ後√←縺薙〒繧ｷ繝｣繝ｪ繧呈ｮ九☆縺九ｒDP
int main(void)
{
	int N, M;
	cin >> N >> M;
	if(M > N) M = N;
	Rep(i, N){
		cin >> X[i] >> Y[i];
		diff[i] = X[i] - Y[i];
	}
	int count = 0;
	int target = 1000;
	int borderID;
	int borderDiff;
	while(1){
		for(int i = N - 1; i >= 0; i--){
			if(diff[i] == target){
				count++;
				if(count == M){
					borderID = i;
					borderDiff = target;
					goto L;
				}
				selected[i] = 1;
			}
		}
		target--;
	}
L:;
	//PrintLn("borderID = " << borderID);
	int ans = 0;
	count = 0;
	Rep(i, N){
		if(selected[i]){
			ans += X[i];
			count++;
		}else{
			if(count == M - 1){
				if(dp[0] == 0){
					dp[0] = Y[i];
					dp[1] = X[i];
				}else{
					dp[1] = max(dp[1], dp[0] + X[i]);
					dp[0] += Y[i];
				}
			}else{
				ans += Y[i];
			}
		}
	}
	int dp_result = dp[1]; // 繧ｷ繝｣繝ｪ霎ｼ縺ｿ縺ｧ鬟溘∋縺溷ｹｸ遖丞ｺｦ
	if(dp_result > borderDiff){
		//PrintLn("dp_result = " << dp_result << " " << borderDiff);
		ans += dp_result;
	}else{
		//PrintLn("borderDiff" << borderDiff << " " << dp_result);
		ans += borderDiff;
	}
	PrintLn(ans);
	return 0;
}
