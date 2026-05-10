//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const int MOD = 1e9+7;
//}}}

ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
  ll N, K;
  cin >> N >> K;

  vector<pair<int, int>> v;
  rep(i, N){
    int a, b;
    cin >> a >> b;
    v.emplace_back(a, b);
  }
  sort(v.begin(), v.end());

  int i = 0;
  int ans = 0;
  rep(i, N){
    K -= v[i].second;
    if(K <= 0){
      ans = v[i].first;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
