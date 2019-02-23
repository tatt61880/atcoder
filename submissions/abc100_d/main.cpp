//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,b
egin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const ll MOD = 998244353;
//}}}

ll x[1000];
ll y[1000];
ll z[1000];
ll w[1000];
int main(){
  ll N, M;
  cin >> N >> M;
  ll ans = 0;
  rep(i, N){
    cin >> x[i];
    cin >> y[i];
    cin >> z[i];
  }

  rep(i, 8){
    rep(j, N){
      w[j] = 0;
      w[j] += ((i & 1) ? x[j] : -x[j]);
      w[j] += ((i & 2) ? y[j] : -y[j]);
      w[j] += ((i & 4) ? z[j] : -z[j]);
    }
    sort(w, w + N);
    reverse(w, w + N);
    ll sum = 0;
    rep(j, M) sum += w[j];
    ans = max(abs(sum), ans);
  }
  cout << ans << endl;
  return 0;
}
