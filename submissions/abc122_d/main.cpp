//{{{
#include <bits/stdc++.h>
using namespace std;
#define repX(a,b,c,x,...) x
#define repN(a) repX a
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop))(__VA_ARGS__)
#define rrep(...) repN((__VA_ARGS__,rrep3,rrep2))(__VA_ARGS__)
#define loop(n) rep2(i_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep3(i,begin,end) for(int i=(int)(begin-1),i##_end=(int)(end);i>=i##_end;--i)
#define foreach(x,a) for(auto&x:a)
using ll=long long;
const ll mod=(ll)1e9+7;
//}}}

// dp[c3][c2][c1][i]
// 3つ前がc3、2つ前がc2、1つ前がc1。i番目。
int dp[4][4][4][101];

int main(){
  int N;
  cin >> N;
  rep(c3, 4) rep(c2, 4) rep(c1, 4) dp[c3][c2][c1][3] = 1;
  dp[0][1][2][3] = 0;
  dp[1][0][2][3] = 0;
  dp[0][2][1][3] = 0;

  rep(i, 3, N) rep(c3, 4) rep(c2, 4) rep(c1, 4){
    int vv = c2 * 10 + c1;
    int vvv = c3 * 100 + vv;
    if(vv == 1 || vv == 10 || vvv == 11 || vvv == 13 || vvv == 31){
      dp[c2][c1][2][i + 1] -= dp[c3][c2][c1][i];
    }else if(vv == 2){
      dp[c2][c1][1][i + 1] -= dp[c3][c2][c1][i];
    }
    rep(x, 4){
      dp[c2][c1][x][i + 1] += dp[c3][c2][c1][i];
      dp[c2][c1][x][i + 1] %= mod;
    }
  }

  ll ans = 0;
  rep(c3, 4) rep(c2, 4) rep(c1, 4) ans = (ans + dp[c3][c2][c1][N]) % mod;
  cout << ans << endl;
  return 0;
}
