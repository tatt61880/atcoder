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

int dp[3][100000];
int abc[3][100000];

int main(){
  int N;
  cin >> N;
  rep(i, N){
    rep(j, 3){
      cin >> abc[j][i];
    }
  }
  rep(j, 3){
    dp
[j][0] = abc[j][0];
  }
  rep(i, 1, N){
    rep(j, 3){
      rep(k, 1, 3){
        int abcId = (j + k) % 3;
        dp[j][i] = max(dp[j][i], dp[abcId][i - 1] + abc[j][i]);
      }
    }
  }

  int ans = 0;
  rep(j, 3){
    ans = max(ans, dp[j][N - 1]);
  }
  cout << ans << endl;
  return 0;
}
