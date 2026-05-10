//{{{
#include <bits/stdc++.h>
using namespace std;
//}}}

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 0;
  while(a != b || b != c){
    if(a > b) swap(a, b);
    if(a > c) swap(a, c);
    if(b > c) swap(b, c);
    ans++;
    if(a == b){
      a++;
      b++;
    }else{
      a+=2;
    }
  }
  cout << ans << endl;
  return 0;
}
