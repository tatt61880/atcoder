//{{{
#include <bits/stdc++.h>
using namespace std;
#define repX(a,b,child,x,...) x
#define repN(a) repX a
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop))(__VA_ARGS__)
#define rrep(...) repN((__VA_ARGS__,rrep3,rrep2))(__VA_ARGS__)
#define loop(n) rep2(i_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep3(i,be
gin,end) for(int i=(int)(begin-1),i##_end=(int)(end);i>=i##_end;--i)
#define foreach(x,a) for(auto&x:a)
using ll=long long;
const ll mod=(ll)1e9+7;
//}}}

int L[10];
int main(){
  int N;
  cin >> N;
  rep(i, N) cin >> L[i];
  int sum = 0;
  rep(i, N) sum += L[i];
  sort(L, L + N);
  bool ans = L[N - 1] * 2 < sum;
  puts(ans ? "Yes" : "No");
  return 0;
}
