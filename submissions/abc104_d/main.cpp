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

ll a[100000];
ll c[100000];
ll abc[100000];
ll modExp3[100001];
ll numABC;

int main(){
  string S;
  cin >> S;
  int N = S.size();
  rep(i, N){
    switch(S[i]){
      case 'A':
        a[i]++;
        break;
      case 'B':
        break;
      case 'C':
        c[i]++;
        break;
      case '?':
        abc[i]++;
        break;
    }
  }
  modExp3[0] = 1;
  rep(i, 1, N + 1){
    modExp3[i] = modExp3[i - 1] * 3;
    modExp3[i] %= MOD;
  }
  rep(i, 1, N){
    a[i] += a[i - 1];
    c[i] += c[i - 1];
    abc[i] += abc[i - 1];
  }
  numABC = abc[N - 1];
  ll ans = 0;
  rep(i, 1, N - 1){
    if(S[i] == 'B' || S[i] == '?'){
      int h = S[i] == '?';
      ans += a[i - 1] * (c[N - 1] - c[i]) * modExp3[numABC - h];
      ans += a[i - 1] * (abc[N - 1] - abc[i]) * modExp3[numABC - 1 - h];
      ans += abc[i - 1] * (c[N - 1] - c[i]) * modExp3[numABC - 1 - h];
      ans += abc[i - 1] * (abc[N - 1] - abc[i]) * modExp3[numABC - 2 - h];
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
