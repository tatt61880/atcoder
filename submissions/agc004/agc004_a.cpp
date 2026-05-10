#include  <iostream>
using namespace std;
int main(void){
 long long a,b,c;
 cin >> a >> b >> c;
 long long min = a * b;
 if(b*c < min) min = b * c;
 if(c*a < min) min = c * a;
 if(a * b * c % 2 == 0){
  cout << 0 << endl;
 }else{
  cout << min << endl;
 }
 return 0;
}