//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#defi
ne foreach(x,a) for(auto &x:a)
typedef long long ll;
const int MOD = 1e9+7;
//}}}

char board[300][300];
int main(){
	int N;
	cin >> N;
	rep(i, N) cin >> board[i];
	int count = 0;
	rep(A, N){
		bool flag = true;
		rep(i, N) rep(j, N){
			if(board[(i + A) % N][j] != board[(j + A) % N][i]){
				flag = false;
			}
		}
		if(flag){
			count += N;
		}
	}
	cout << (count) << endl;
	return 0;
}
