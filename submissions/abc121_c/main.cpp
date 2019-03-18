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
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> AB;
  rep(i, N){
    int a, b;
    cin >> a >> b;
    AB.emplace_back(a, b);
  }
  sort(AB.begin(), AB.end());
  ll ans = 0;
  rep(i, N){
    ll a = AB[i].first;
    ll b = AB[i].second;
    if(M - b > 0){
      ans += b * a;
      M -= b;
    }else{
      ans += M * a;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
