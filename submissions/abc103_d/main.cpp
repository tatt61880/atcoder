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

pair<int, int> p[100000];
int b[100000];
int main(){
  int N, M;
  cin >> N >> M;
  rep(i, M){
    int a, b;
    cin >> a >> b;
    p[i] = make_pair(a, b);
  }
  sort(p, p + M);
  int ans = 1;
  int pos = p[0].second;
  rep(i, M){
    int l = p[i].first;
    int r = p[i].second;
    if(r < pos){
      pos = r;
    }else if(pos <= l){
      ans++;
      pos = r;
    }
  }
  cout << ans << endl;
  return 0;
} 
