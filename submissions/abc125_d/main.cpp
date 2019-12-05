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
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  bool include_zero = false;
  rep(i, N){
    if(A[i] == 0) include_zero = true;
  }

  ll ans = 0;
  if(include_zero){
    rep(i, N){
      ans += abs(A[i]);
    }
  }else{
    ll count_minus = 0;
    rep(i, N){
      if(A[i] < 0) count_minus++;
    }
    ll sum = 0;
    rep(i, N){
      A[i] = abs(A[i]);
    }
    rep(i, N){
      sum += A[i];
    }
    if(count_minus % 2 == 0){
      ans = sum;
    }else{
      ans = sum;
      ll mn = A[0];
      rep(i, N){
        mn = min(mn, A[i]);
      }
      ans -= mn * 2;
    }
  }
  cout << ans << endl;
  return 0;
}
