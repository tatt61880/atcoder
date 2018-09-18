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
ll a[10000];
ll b[10000];
int main(){
  int N;
  cin >> N;
  rep(i, N) cin >> a[i];
  rep(i, N) cin >> b[i];
  ll sumA = 0;
  ll sumB = 0;
  ll count = 0;
  rep(i, N){
    sumA += a[i];
    sumB += b[i];
    if(a[i] < b[i]) count += (b[i] - a[i] + 1) / 2;
  }
  bool ans = (count <= sumB - sumA);
  puts(ans ? "Yes" : "No");
  return 0;
}
