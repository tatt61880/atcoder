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
  string S;
  cin >> S;
  int x = (S[0] - '0') * 10 + S[1] - '0';
  int y = (S[2] - '0') * 10 + S[3] - '0';
  bool a = (0 <= x && x <= 99 && 1 <= y && y <= 12);
  bool b = (0 <= y && y <= 99 && 1 <= x && x <= 12);

  if(a){
    if(b){
      puts("AMBIGUOUS");
    }else{
      puts("YYMM");
    }
  }else{
    if(b){
      puts("MMYY");
    }else{
      puts("NA");
    }
  }
  return 0;
}
