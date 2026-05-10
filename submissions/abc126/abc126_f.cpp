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

int main(){
  int M, K;
  cin >> M >> K;
  int max_num = 1;
  rep(i, M){
    max_num *= 2;
  }
  max_num--;

  if(K == 0){
    rep(i, max_num + 1){
      if(i != max_num){
        printf("%d %d ", i, i);
      }else{
        printf("%d %d\n", i, i);
      }
    }
  }else if(max_num >= K){
    if(M == 1 && K == 1){
      puts("-1");
      return 0;
    }
    printf("%d", K);
    rep(i, max_num + 1){
      if(i != K) printf(" %d", i);
    }
    printf(" %d", K);
    rrep(i, max_num + 1){
      if(i != K) printf(" %d", i);
    }
  }else{
    puts("-1");
  }
  return 0;
}
