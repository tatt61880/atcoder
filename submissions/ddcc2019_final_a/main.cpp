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
int countl[100000];
int countr[100000];
int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int count;
  count = 0;
  rep(i, N){
    if(S[i] == '>'){
      count++;
    }else{
      countl[i] = count;
      count = 0;
    }
  }
  count = 0;
  rrep(i, N){
    if(S[i] == '>'){
      count++;
    }else{
      countr[i] = count;
      count = 0;
    }
  }
  int maxCountSum = -1;
  int id;
  count = 0;
  rep(i, N){
    if(S[i] == '-'){
      int cnt = countl[i] + countr[i];
      if(cnt > maxCountSum){
        maxCountSum = cnt;
        id = i;
      }
    }
  }
  S[id] = '>';
  double ans = 0;
  rep(i, N){
    if(S[i] == '>'){
      ans += 1.0 / (count + 2.0);
      count++;
    }else{
      count = 0;
      ans += 1.0;
    }
  }
  printf("%.14lf\n", ans);
  return 0;
}
