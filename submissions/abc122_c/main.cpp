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
int ac_num[100001];
int main(){
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  rep(i, 1, N){
    ac_num[i + 1] = ac_num[i] + (S[i] == 'C' && S[i - 1] == 'A' ? 1 : 0);
  }
  rep(i, Q){
    int l, r;
    cin >> l >> r;
    int ans = ac_num[r] - ac_num[l];
    cout << ans << endl;
  }
  return 0;
}
