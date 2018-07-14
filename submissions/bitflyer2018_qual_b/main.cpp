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
const int MOD = 1e9+7;
//}}}

ll a[200000];
int main(){
  int A, B, N;
  string X;
  cin >> A >> B >> N;
  cin >> X;
  rep(i, N){
    switch(X[i]){
      case 'S':
        A--;
        break;
      case 'C':
        B--;
        break;
      case 'E':
        if(A >= B) A--;
        else B--;
        break;
    }
  }
  A = max(A, 0);
  B = max(B, 0);
  cout << A << endl << B << endl;
  return 0;
}
