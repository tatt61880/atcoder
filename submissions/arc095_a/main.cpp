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

int x[200000];
int y[200000];
int main(){
  int N;
  cin >> N;
  rep(i, N) cin >> x[i];
  rep(i, N) y[i] = x[i];
  sort(x, x + N);

  rep(i, N){
    if(y[i] < x[N / 2]){
      cout << x[N / 2] << endl;
    } else {
      cout << x[N / 2 - 1] << endl;
    }
  }
  return 0;
}
