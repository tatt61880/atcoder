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

ll A[100000];
ll B[100000];
ll diff[100000];
int main(){
  int N;
  cin >> N;
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  ll sumA = 0;
  ll sumB = 0;
  rep(i, N) sumA += A[i];
  rep(i, N) sumB += B[i];
  if(sumA < sumB){
    puts("-1");
    return 0;
  }
  rep(i, N) diff[i] = A[i] - B[i];
  sort(diff, diff + N);
  reverse(diff, diff + N);
  /*
  rep(i, N){
    printf("diff = %lld\n", diff[i]);
  }
  */
  ll sum = 0;
  ll ans = 0;
  rep(i, N){
    if(A[i] < B[i]){
      sum += B[i] - A[i];
      ans++;
    }
  }
  rep(i, N){
    if(sum <= 0){
      printf("%lld\n", ans);
      return 0;
    }
    //printf("sum = %lld\n", sum);
    sum -= diff[i];
    ans++;
  }
  return 0;
}
