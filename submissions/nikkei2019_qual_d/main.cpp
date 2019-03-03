//{{{
#include <bits/stdc++.h>
using namespace std;
#define repX(a,b,child,x,...) x
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
vector<int> V[100001];
vector<int> v;
int visited[100001];
int ans[100001];
void tsort(int x){
  if(visited[x]) return;
  visited[x] = 1;
  for(auto y: V[x]){
    tsort(y);
  }
  v.push_back(x);
}
int main(){
  int N, M;
  cin >> N >> M;
  rep(i, N + M - 1){
    int a, b;
    cin >> a >> b;
    V[a].push_back(b);
  }
  rep(i, N) tsort(i + 1);
  reverse(v.begin(), v.end());
  for(int parent: v){
    for(int child: V[parent]){
      ans[child] = parent;
    }
  }
  rep(i, N) cout << ans[i + 1] << endl;
  return 0;
}
