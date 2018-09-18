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
int main(){
  ll N, K;
  cin >> N >> K;
  ll ans;
  if(K % 2){
    ans = N / K;
    ans = ans * ans * ans;
  }else{
    ans = N / K;
    ans = ans * ans * ans;
    ll ans2 = (N + K / 2) / K;
    ans2 = ans2 * ans2 * ans2;
    ans += ans2;
  }
  cout << ans << endl;
  return 0;
}
