//{{{
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
const int MOD = 1e9+7;
//}}}

int A[2][100];
int main(){
	int N;
	cin >> N;
	rep(i, 2) rep(j, N) cin >> A[i][j];
	int ans=0;
	rep(i,N){
		int sum=0;
		rep(j,0,i+1) sum+=A[0][j];
		rep(j,i,N) sum+=A[1][j];
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
