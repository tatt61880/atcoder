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
//}}}

int K;

bool in(int x, int y, int r)
{
  return x * x + y * y <= r * r;
}

int num(int size)
{
  int res = 0;
  int r = size / 2;
  rep(i, size / K){
    rep(j, size / K){
      int min_x = i * K - r;
      int min_y = j * K - r;
      int max_x = min_x + K;
      int max_y = min_y + K;
      if(in(min_x, min_y, r) &&
          in(max_x, min_y, r) &&
          in(min_x, max_y, r) &&
          in(max_x, max_y, r)){
        res++;
      }
    }
  }
  return res;
}

int main(void)
{
  cin >> K;
  cout << num(200) << " " << num(300) << endl;
  return 0;
}
