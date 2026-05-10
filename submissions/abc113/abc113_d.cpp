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

int ans[2][8];

int main(){
  int H, W, K;
  cin >> H >> W >> K;

  ans[0][0] = 1;
  rep(h, H){
    rep(w, W){
      ans[1][w] = 0;
    }
    rep(id, 1 << (W - 1)){
      int x[9] = {0};
      rep(w, W - 1){
        x[w + 1] = (id >> w) & 1;
      }
      bool f = false;
      rep(w, W - 2){
        if(x[w + 1] && x[w + 2]) f = true;
      }
      if(f) continue;
      rep(w, W){
        if(x[w]){
          ans[1][w] += ans[0][w - 1];
        }else if(x[w + 1]){
          ans[1][w] += ans[0][w + 1];
        }else{
          ans[1][w] += ans[0][w];
        }
        ans[1][w] %= mod;
      }
    }
    rep(w, W){
      ans[0][w] = ans[1][w];
    }
  }
  cout << ans[1][K - 1] << endl;
  return 0;
}
