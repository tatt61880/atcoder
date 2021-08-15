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

int color[100000];
vector<pair<int, ll>> vv[100000];

int main(){
  int N, M;
  cin >> N >> M;
  rep(i, N){
    color[i] = -1;
  }
  rep(i, M){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    vv[u].emplace_back(v, w);
    vv[v].emplace_back(u, w);
  }
  int ans = 0;
  rep(i, N){
    if(color[i] == -1){
      ans++;
      stack<int> st;
      color[i] = 0;
      st.push(i);
      while(st.size()){
        int a = st.top();
        int current_color = color[a];
        st.pop();
        for(auto &x: vv[a]){
          int y = x.first;
          if(color[y] == -1){
            color[y] = 0;
            st.push(y);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
