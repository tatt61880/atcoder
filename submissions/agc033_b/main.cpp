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

int H, W, N;

int main(){
  cin >> H >> W >> N;
  int sy, sx;
  cin >> sy >> sx;
  string S, T;
  cin >> S >> T;

  int ans = true;
  // ←
  {
    int x = sx;
    rep(i, N){
      if(S[i] == 'L') x--;
      if(x == 0) {
        ans = false;
        goto F;
      }
      if(x != W && T[i] == 'R') x++;
    }
  }
  // →
  {
    int x = sx;
    rep(i, N){
      if(S[i] == 'R') x++;
      if(x == W + 1) {
        ans = false;
        goto F;
      }
      if(x != 1 && T[i] == 'L') x--;
    }
  }
  // ↑
  {
    int y = sy;
    rep(i, N){
      if(S[i] == 'U') y--;
      if(y == 0) {
        ans = false;
        goto F;
      }
      if(y != H && T[i] == 'D') y++;
    }
  }
  // ↓
  {
    int y = sy;
    rep(i, N){
      if(S[i] == 'D') y++;
      if(y == H + 1) {
        ans = false;
        goto F;
      }
      if(y != 1 && T[i] == 'U') y--;
    }
  }

F:
  puts(ans ? "YES" : "NO");
  return 0;
}
