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
const ll mod=(ll)998244353;
//}}}


int w[200001];
int b[200001];

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  b[0] = 0;
  rep(i, 1, N + 1){
    b[i] = b[i - 1] + (S[i - 1] == '#');
  }
  w[N] = 0;
  rrep(i, N){
    w[i] = w[i + 1] + (S[i] == '.');
  }
  int ans = N;
  rep(i, N + 1){
    ans = min(ans, b[i] + w[i]);
  }
  cout << ans << endl;
  return 0;
}
