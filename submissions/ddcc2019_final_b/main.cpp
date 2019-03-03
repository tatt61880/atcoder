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
int ans[100000];
int main(){
  ll N, K, R;
  cin >> N >> K >> R;
  ll mx = (N - K) * (1 + N - K) / 2;
  if(mx < R){
    puts("No Luck");
    return 0;
  }
  //printf("mx=%lld\n", mx);
  int diff = N - K;
  rep(i, N){
    int n = i + 1;
    if(R <= mx - diff){
      ans[i] = n;
      mx -= diff;
      //printf("mx=%lld\n", mx);
      diff--;
    }else{
      diff = mx - R;
      //printf("diff=%d\n", diff);
      int num = N - K - diff;
      ans[num] = n;
      i++;
      int id = N - 1;
      for(; i < N; i++){
        n = i + 1;
        if(id == num) id--;
        ans[id] = n;
        id--;
      }
    }
  }
  rep(i, N){
    printf("%d%c", ans[i], i != N - 1 ? ' ' : '\n');
  }
#if 0
  int count = 0;
  rep(i, N){
    rep(j, i + 1, N){
      if(ans[i] >= ans[j] + K){
        printf("(%d, %d)\n", ans[i], ans[j]);
        count++;
      }
    }
  }
  if(count == R){
    printf("OK\n");
  }else{
    printf("NG(%d)\n", count);
  }
#endif
  return 0;
}
