#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{
 int n;
 cin >> n;
 int aaa, aa;
 int bbb, bb, b;
 cin >> aaa >> aa;
 bb = 0; b = abs(aa - aaa);
 
 for(int i = 2; i < n; i++){
  int a;
  cin >> a;
  bbb = bb;
  bb = b;
  b = min(b
bb + abs(a - aaa), bb + abs(a - aa));
  aaa = aa;
  aa = a;
 }
 cout << b << endl;
 return 0;
}
