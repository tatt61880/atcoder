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
const ll MOD=(ll)1e9+7;
//}}}

int f(int a, int b){
  int res;
  if(b < 0){
    res = -a;
  }else if(a > 0){
    res = b;
  }else{
    res = 2 * min(-a, b) + max(-a, b);
  }
  return res;
}

int x[100000];
int main(){
  int N, K;
  cin >> N >> K;
  rep(i, N) cin >> x[i];
  int ans = f(x[0], x[K - 1]);
  rep(i, N - K + 1){
    ans = min(ans, f(x[i], x[i + K - 1]));
  }
  cout << ans << endl;
  return 0;
}
