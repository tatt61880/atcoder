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
const ll MOD = 1e9+7;
//}}}

int a[200001];
int b[200001];
int c[200000];
int main(){
  int N, M;
  cin >> N >> M;
  rep(i, M){
    cin >> a[i];
    cin >> b[i];
  }
  bool ans = false;
  rep(i, M){
    if(a[i] == 1) c[b[i]]++;
  }
  rep(i, M){
    if(b[i] == N && c[a[i]]) ans = true;
  }

  puts(ans ? "POSSIBLE" : "IMPOSSIBLE");
  return 0;
}
