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

int N, K;
string S;

void moveL(int &n){
  while(n != N - 1 && S[n] == '1') n++;
  while(n != N - 1 && S[n] == '0') n++;
}

void moveR(int &n){
  while(n < N && S[n] == '0') n++;
  if(S[n] == '0') n++;
  while(n < N && S[n] == '1') n++;
  if(S[n] == '1') n++;
}

int main(){
  cin >> N >> K;
  cin >> S;
  int ans = 0;
  int l = 0;
  int r = 0;

  if(S[0] == '1') moveR(r);
  rep(i, K) moveR(r);
  while(true){
    //printf("%d %d\n", l, r);
    ans = max(ans, r - l);
    if(r == N) break;
    moveL(l);
    moveR(r);
  }
  cout << ans << endl;
  return 0;
}
