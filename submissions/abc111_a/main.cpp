#include <iostream>
using namespace std;

int main()
{
  string s;
  cin >> s;
  for(auto &x: s){
    cout << (x == '1' ? 9 : 1);
  }
  cout << endl;
  return 0;
}