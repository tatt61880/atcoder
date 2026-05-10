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


int main()
{
  int N = 5;
  vector<int> a(5);
  rep(i, N) cin >> a[i];
  int ans = 0;
  int max_loss = 0;
  foreach(x, a){
    int t = (x + 9) / 10 * 10;
    ans += t;
    max_loss = max(max_loss, t - x);
  }
  ans -= max_loss;
  cout << ans << endl;
  return 0;
}
