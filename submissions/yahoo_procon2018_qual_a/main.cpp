#include <iostream>
#include <cstring>
using namespace std;
int main(){
 char s[6];
 cin >> s;
 bool ans = true;
 if(s[4] != s[3]) ans = false;
 if(strncmp(s, "yah", 3)) ans = false;
 cout << (ans ? "YES" : "NO") << endl;
 return 0;
}