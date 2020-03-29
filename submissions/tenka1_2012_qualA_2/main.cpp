#include <bits/stdc++.h>
using namespace std;
int main(){
  string ans;
  getline(cin, ans);
  ans = regex_replace(ans, regex(" +"), ",");
  cout << ans << endl;
}
