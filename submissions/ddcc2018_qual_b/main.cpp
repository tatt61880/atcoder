//{{{
#include <bits/stdc++.h>
using namespace std;
#define repX(a,b,c,x,...) x
#define repN(a) repX a
#define rep(...) repN((
__VA_ARGS__,rep3,rep2,loop))(__VA_ARGS__)
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

int N;

bool f(int x, int y){
  if(x < 0) x *= -1;
  if(y < 0) y *= -1;
  return x + y <= N;
}

int main(){
  cin >> N;
  int ans = 0;
  rep(i, N){
    rep(j, N){
      int x = i * 2 - N;
      int y = j * 2 - N;
      if(f(x, y) && f(x + 2, y) && f(x + 2, y + 2) && f(x, y + 2)) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
