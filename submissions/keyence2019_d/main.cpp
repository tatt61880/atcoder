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

int A[1000];
int B[1000];
int main(){
  int N, M;
  cin >> N >> M;
  rep(i, N) cin >> A[i];
  rep(i, M) cin >> B[i];
  sort(A, A + N); reverse(A, A + N);
  sort(B, B + M); reverse(B, B + M);
  ll ans = 1;
  int na = 0;
  int nb = 0;
  int fixed = 0;
  rrep(i, N * M + 1, 1){
    if(i == A[na] && i == B[nb]){
      na++;
      nb++;
    }else if(i == A[na]){
      na++;
      ans *= nb; ans %= mod;
    }else if(i == B[nb]){
      nb++;
      ans *= na; ans %= mod;
    }else{
      ans *= (na * nb - fixed); ans %= mod;
    }
    fixed++;
  }
  cout << ans << endl;
  return 0;
}
