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

int x[100];
int y[100];
int h[100];

int f(int dx, int dy, int hh){
  return hh + abs(dx) + abs(dy);
}

int main(){
  int N;
  cin >> N;
  rep(i, N) cin >> x[i] >> y[i] >> h[i];

  rep(i, N){
    if(h[i]){
      swap(x[i], x[0]);
      swap(y[i], y[0]);
      swap(h[i], h[0]);
      break;
    }
  }

  rep(cx, 101){
    rep(cy, 101){
      int H = f(x[0] - cx, y[0] - cy, h[0]);
      rep(i, 1, N){
        if(f(x[i] - cx, y[i] - cy, h[i]) == H) continue;
        if(h[i] == 0 && f(x[i] - cx, y[i] - cy, h[i]) >= H) continue;
        goto F;
      }
      printf("%d %d %d\n", cx, cy, H);
      return 0;
F:;
    }
  }
}
