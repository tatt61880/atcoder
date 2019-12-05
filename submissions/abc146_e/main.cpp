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
ll A[200000];
ll B[200005];
int main(){
  int N, K;
  cin >> N >> K;
  rep(i, N){
    cin >> A[i];
  }
  rep(i, N){
    B[i + 1] = B[i] + A[i];
    B[i + 1] %= K;
  }
  rep(i, N + 1){
    B[i] += N - i;
    B[i] %= K;
  }
  map<ll, int> mp;
  rep(i, N + 1){
    mp[B[i]]++;
  }
  //rep(i, N + 1){ cout << B[i] << " "; } cout << endl;
  // rep(i, N + 1){ cout << mp[i] << " "; } cout << endl;
  map<int, int> cnt;
  int l = 0;
  int r = min(N, K - 1);
  ll ans = 0;
  rep(i, r + 1){
    ans += cnt[B[i]];
    cnt[B[i]]++;
  }
  //cout << ans << endl;
  while(1){
    if(r == N) break;
    cnt[B[l]]--;
    l++;
    r++;
    ans += cnt[B[r]];
    cnt[B[r]]++;
  }
  cout << ans << endl;
  return 0;
}
