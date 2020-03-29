#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  bool ans = regex_match(s, regex("A?KIHA?BA?RA?"));
  puts(ans ? "YES" : "NO");
}
