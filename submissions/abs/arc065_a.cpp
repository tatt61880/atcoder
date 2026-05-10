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
const ll MOD = 998244353;
//}}}

int main(){
  char S[100001];
  cin >> S;
  reverse(S, S + strlen(S));
  bool ans = true;
  int p = 0;
  while(p != strlen(S)){
    if(strncmp(S + p, "resare", 6) == 0) {p+=6; continue;}
    if(strncmp(S + p, "esare", 5) == 0) {p+=5; continue;}
    if(strncmp(S + p, "remaerd", 7) == 0) {p+=7; continue;}
    if(strncmp(S + p, "maerd", 5) == 0) {p+=5; continue;}
    ans = false;
    break;
  }
  puts(ans ? "YES" : "NO");
  return 0;
}
