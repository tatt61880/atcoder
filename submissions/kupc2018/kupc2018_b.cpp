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

char c[10][11];

int main(){
  int H, W;
  cin >> H >> W;
  rep(h, H) cin >> c[H - 1 - h];
  int startPos = -1;
  rep(w, W) if(c[0][w] == 's') startPos = w;
  rep(i, pow(3, H - 1)){
    int num = i;
    int pos = startPos;
    rep(j, 1, H){
      switch(num % 3){
      case 0: pos--; break;
      case 1: break;
      case 2: pos++; break;
      }
      num /= 3;
      if(pos < 0 || W <= pos) goto F;
      if(c[j][pos] == 'x') goto F;
    }
    rep(j, 1, H){
      switch(i % 3){
      case 0: cout << 'L'; break;
      case 1: cout << 'S'; break;
      case 2: cout << 'R'; break;
      }
      i /= 3;
    }
    cout << endl;
    return 0;
F:;
  }
  cout << "impossible" << endl;
  return 0;
}
