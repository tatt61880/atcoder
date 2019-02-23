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
#define rrep3(i,begin,end) for(int i=(in
t)(begin-1),i##_end=(int)(end);i>=i##_end;--i)
#define foreach(x,a) for(auto&x:a)
using ll=long long;
const ll mod=(ll)1e9+7;
//}}}

ll x[200000];
ll y[200000];
ll maxY[200000];
set<ll> st;

int main(){
  ll H, W, N;
  // cin >> H >> W >> N;
  cin >> W >> H >> N;
  rep(i, N){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    st.insert(y[i] * W + x[i]);
  }
  maxY[0] = 0;
  rep(w, 1, W){
    if(st.count((maxY[w - 1] + 1) * W + w)){
      maxY[w] = maxY[w - 1];
    }else{
      maxY[w] = maxY[w - 1] + 1;
    }
  }

  ll ans = W;
  rep(i, N){
    ll xx = x[i];
    ll yy = y[i];
    if(yy <= maxY[xx - 1]){
      ans = min(ans, xx);
    }
  }
  cout << ans << endl;
  return 0;
}
