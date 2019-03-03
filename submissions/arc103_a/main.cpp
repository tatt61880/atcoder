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
//}}}
int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  map<int, int> mo;
  map<int, int> me;
  rep(i, n) (i % 2 ? mo : me)[v[i]]++;
  vector<pair<int, int>> vo;
  vector<pair<int, int>> ve;
  for(auto x: mo) vo.emplace_back(x.second, x.first);
  for(auto x: me) ve.emplace_back(x.second, x.first);
  sort(vo.rbegin(), vo.rend());
  sort(ve.rbegin(), ve.rend());
  int ans;
  if(vo[0].second != ve[0].second){
    ans = n - vo[0].first - ve[0].first;
  }else{
    ans = n + 1;
    if(vo.size() > 1) ans = min(ans, n - vo[1].first - ve[0].first);
    if(ve.size() > 1) ans = min(ans, n - vo[0].first - ve[1].first);
    if(ans == n + 1) ans = n / 2;
  }
  cout << ans << endl;
  return 0;
}
