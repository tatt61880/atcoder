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
const ll MOD=(ll)1e9+7;
//}}}

void f(string s, string t)
{
  rep(i, s.size()){
    if(s[i] != t[i]){
      char si = s[i];
      char ti = t[i];
      rep(j, s.size()){
        if(s[j] == si) s[j] = ti;
        else if(s[j] == ti) s[j] = si;
      }
    }
  }
  bool ans = s == t;
  puts(ans ? "Yes" : "No");
}

int main(){
  string s, t;
  cin >> s >> t;
  char ch[26];
  rep(i, 26){
    ch[i] = '.';
  }
  vector<pair<char, char>> v;
  rep(i, s.size()){
    v.emplace_back(t[i], s[i]);
  }
  sort(v.begin(), v.end());

  string newS;
  string newT;

  bool flag = true;
  foreach(x, v){
    char ct = x.first;
    char cs = x.second;
    char last_cs;
    char last_ct;
    if(flag){
      flag = false;
      newS = cs;
      newT = ct;
      last_cs = cs;
      last_ct = ct;
      continue;
    }
    if(last_cs != cs || last_ct != ct){
  
    newS += cs;
      newT += ct;
    }
  }

  f(newS, newT);
  return 0;
}
