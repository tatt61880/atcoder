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
#define rrep3(i,begin,
end) for(int i=(int)(begin-1),i##_end=(int)(end);i>=i##_end;--i)
#define foreach(x,a) for(auto&x:a)
using ll=long long;
const ll mod=(ll)1e9+7;
//}}}

ll p[51];
ll t[51];

int f(int outsideLevel, ll remains){
  int includedLevel = outsideLevel;
  while(1){
    if(t[includedLevel] + outsideLevel - includedLevel <= remains){
      return includedLevel;
    }
    includedLevel--;
    if(!includedLevel) return 0;
  }
}

int main(){
  int N;
  ll X;
  cin >> N >> X;
  p[0] = 1;
  t[0] = 1;
  rep(i, 50){
    p[i + 1] = 2 * p[i] + 1;
    t[i + 1] = 2 * t[i] + 3;
  }

  ll ans = 0;
  int outsideLevel = N;
  ll remains = X;
  while(remains){
    int includedLevel = f(outsideLevel, remains);
    if(includedLevel == 0){
      if(remains - outsideLevel > 0) ans += remains - outsideLevel;
      break;
    }
    remains -= t[includedLevel] + outsideLevel - includedLevel;
    ans += p[includedLevel];
    if(!remains) break;
    ans++;
    remains--;
    ou
tsideLevel = includedLevel;
  }

  cout << ans << endl;
  return 0;
}
