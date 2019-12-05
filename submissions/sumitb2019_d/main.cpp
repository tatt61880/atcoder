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

int dp1[10];
int dp2[100];
int dp3[1000];

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;

  rep(i, N){
    int d = S[i] - '0';
    int d2 = -1;
    int d3 = -1;
    rep(j, 100) if(dp2[j]) {
      d3 = j * 10 + d;
      dp3[d3] = 1;
    }
    rep(j, 10) if(dp1[j]) {
      d2 = j * 10 + d;
      dp2[d2] = 1;
    }
    dp1[d] = 1;
  }
  int ans = 0;
  rep(i, 1000){
    if(dp3[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
