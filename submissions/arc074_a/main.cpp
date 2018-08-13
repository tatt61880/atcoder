//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const ll MOD = 1e9+7;
//}}}

int main(){
  ll H, W;
  cin >> H >> W;

  if(H % 3 == 0 || W % 3 == 0){
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1e18;
  ll Smin;
  ll Smax;
  ll S1;
  ll S2;
  ll S3;
  rep(x, 2){
    rep(i, 1, W){
      S1 = i * H;
      S2 = H / 2 * (W - i);
      S3 = (H - H / 2) * (W - i);
      Smin = min(min(S1, S2), S3);
      Smax = max(max(S1, S2), S3);
      ans = min(Smax - Smin, ans);
    }
    swap(H, W);
  }
  ans = min(min(W, H), ans);
  cout << ans << endl;
  return 0;
}
