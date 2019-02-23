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
const ll MOD=(ll)998244353;
//}}}

bool a[100];
i
nt main(){
  int N, M, A, B;
  cin >> N >> M >> A >> B;
  rep(i, M){
    int l, r;
    cin >> l >> r;
    rep(j, l - 1, r){
      a[j] = true;
    }
  }
  int ans = 0;
  rep(i, N){
    ans += a[i] ? A : B;
  }
  cout << ans << endl;

  return 0;
}
