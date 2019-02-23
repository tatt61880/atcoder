//{{{
#include "bits/stdc++.h"
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,..
.) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const int MOD = 1e9+7;
//}}}

int parents[100001];
int p[100001];
int root(int x){
  if(parents[x] == x){
    return x;
  }else{
    return parents[x] = root(parents[x]);
  }
}

void unite(int x, int y){
  x = root(x);
  y = root(y);
  if(x == y) return;
  parents[x] = y;
}

int main(){
  int N, M;
  cin >> N >> M;
  rep(i, N) cin >> p[i];
  rep(i, 1, N){
    parents[i] = i;
  }

  rep(i, M){
    int x, y;
    cin >> x >> y;
    unite(x, y);
  }

  int ans = 0;
  rep(i, N){
    int id = i + 1;
    if(root(id) == root(p[i])){
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
