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

const int inf = 100000000;

int l[8];
int N, A, B, C;

int g(vector<int> v, int target){
  if(v.size() == 0) return inf;
  int sum = 0;
  rep(i, v.size()){
    sum += v[i];
  }
  return (v.size() - 1) * 10 + abs(sum - target);
}

int f(vector<int> v[4]){
  int res = 0;
  res += g(v[0], A);
  res += g(v[1], B);
  res += g(v[2], C);
  return res;
}

int main(){
  cin >> N >> A >> B >> C;
  rep(i, N) cin >> l[i];
  int ans = inf;
  rep(i, pow(4, N)){
    int id = i;
    vector<int> v[4];
    rep(j, N){
      v[id % 4].push_back(l[j]);
      id /= 4;
    }
    ans = min(ans, f(v));
  }
  cout << ans << endl;
  return 0;
}
