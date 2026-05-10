#include <iostream>
using namespace std;
int main()
{
  int s, l, r;
  cin >> s >> l >> r;
  if(s < l) s = l;
  if(s > r) s = r;
  cout << s << endl;
}
