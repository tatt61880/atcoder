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
vector<pair<int, int>> v[100000];
int colors[100000];
int finished[100000];
int main(){
  int N;
  cin >> N;
  rep(i, N - 1){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(make_pair(b, i));
    v[b].push_back(make_pair(a, i));
  }
  int start = 0;
  int maxColor = 0;
  rep(i, N){
    if(v[i].size() > maxColor){
      maxColor = v[i].size();
      start = i;
    }
  }
  cout << maxColor << endl;
  queue<pair<int, int>> q;
  q.push(make_pair(start, 0));
  while(q.size()){
    pair<int, int> p = q.front();
    q.pop();
    int id = p.first;
    int color = p.second;
    rep(i, v[id].size()){
      int pp = v[id][i].first;
      int branchId = v[id][i].second;
      if(!finished[branchId]){
        finished[branchId] = 1;
        color++;
        color %= maxColor;
        colors[branchId] = color;
        q.push(make_pair(pp, color));
      }
    }
  }
  rep(i, N - 1){
    if(colors[i] == 0) colors[i] = maxColor;
    cout << colors[i] << endl;
  }
  return 0;
}
