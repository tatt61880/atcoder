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

int main(){
  int xs, ys;
  int xa, ya;
  int xb, yb;
  int xe, ye;
  cin >> xs >> ys;
  cin >> xa >> ya;
  cin >> xb >> yb;
  cin >> xe >> ye;

  const int XSP = 500;
  const int YSP = 500;
  const int XAS = 60;
  const int YAS = 60;
  const int XDS = 60;
  const int YDS = 60;
  const int unit = 2500;
  const int AS = unit;
  const int BS = unit;
  const int ES = unit * 2;

  int xp;
  int yp;
  int as = 0;
  int bs = 0;
  int es = 0;

  xp = xa;
  yp = ya;
  as = AS;
  bs = 0;
  es = 0;
  printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", xp,XSP,XAS,XDS,yp,YSP,YAS,YDS,as,bs,es);
  xp = xb+(xb>897?-3:3);
  yp = yb;
  as = 0;
  bs = BS;
  es = 0;
  printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", xp,XSP,XAS,XDS,yp,YSP,YAS,YDS,as,bs,es);
  xp = xe;
  yp = ye;
  as = 0;
  bs = 0;
  es = ES;
  printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", xp,XSP,XAS,XDS,yp,YSP,YAS,YDS,as,bs,es);

  return 0;
}
