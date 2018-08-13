#include <iostream>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  if(a % b == 0){
    cout << -1 << endl;
  }else{
    cout << a << endl;
  }
  return 0;
}