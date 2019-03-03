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
ll A[100000];
ll B[100000];
int id[100000];
vector<vector<ll>> a;
vector<vector<ll>> b;
int main(){
  int N;
  cin >> N;
  rep(i, N){
    cin >> A[i];
    cin >> B[i];
  }
  rep(i, N){ vector<ll> v = {B[i] + A[i], A[i], A[i] - B[i], i, A[i], A[i], B[i]}; a.emplace_back(v); }
  rep(i, N){ vector<ll> v = {A[i] + B[i], B[i], B[i] - A[i], i, B[i], A[i], B[i]}; b.emplace_back(v); }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
#if 0
  rep(i, N) printf("a[%lld %lld]\n", a[i][5], a[i][6]);
  rep(i, N) printf("b[%lld %lld]\n", b[i][5], b[i][6]);
#endif
  ll ans = 0;
  int ai = 0;
  int bi = 0;
  rep(i, N){
    if(i % 2 == 0){
      while(1){
        if(id[a[ai][3]]){
          ai++;
          continue;
        }
        id[a[ai][3]] = 1;
        ans += a[ai][4];
        break;
      }
    }else{
      while(1){
        if(id[b[bi][3]]){
          bi++;
          continue;
        }
        id[b[bi][3]] = 1;
        ans -= b[bi][4];
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
