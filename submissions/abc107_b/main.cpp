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
char a[101][101];
char b[101][101];
int main(){
  int H, W;
  cin >> H >> W;
  rep(h, H) cin >> a[h];
  rep(h, H){
    bool f = true;
    rep(w, W){
      rep(i, W) if(a[h][i] == '#') f = false;
    }
    if(f) continue;
    rep(w, W){
      bool f = false;
      rep(i, H) if(a[i][w] == '#') f = true;
      if(f) cout << a[h][w];
    }
    cout << endl;
  }
  return 0;
}
