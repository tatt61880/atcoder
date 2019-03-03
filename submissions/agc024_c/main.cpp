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
const int MOD = 1e9+7;
//}}}
ll a[200000];
int main(){
  ll N;
  cin >> N;
  rep(i, N) cin >> a[i];
  if(a[0] != 0){
    cout << "-1" << endl;
    return 0;
  }
  ll ans = 0;
  rep(i, 1, N){
    if(a[i] > a[i - 1] + 1){
      cout << "-1" << endl;
      return 0;
    }
    if(a[i]){
      if(a[i] == a[i - 1] + 1){
        ans++;
      }else{
        if(a[i] == 1){
          ans++;
        }else{
          ans += a[i];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
