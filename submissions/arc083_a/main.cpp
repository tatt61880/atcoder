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
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int ansW = a * 100;
  int ansS = 0;
  double ans = 0;
  rep(ai, 31){
    rep(bi, 31){
      int sumW = a * ai * 100 + b * bi * 100;
      if(sumW == 0) continue;
      int sumS = 0;
      if(sumW >= f) continue;
      for(int ci = 0; sumW + ci * c <= f; ci++){
        for(int di = 0; sumW + ci * c + di * d <= f; di++){
          sumS = ci * c + di * d;
          double g = (double)sumS * 100 / (sumS + sumW);
          if(e * (sumS + sumW) >= sumS * (100 + e) && ans < g){
            ans = g;
            ansW = sumW;
            ansS = sumS;
          }
        }
      }
    }
  }
  cout << (ansW + ansS) << " " << (ansS) << endl;
  return 0;
}
