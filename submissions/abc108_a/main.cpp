#include <iostream>

int main(){
  int K;
  std::cin >> K;
  int ans = (K / 2) * ((K + 1) / 2);
  std::cout << ans << std::endl;
  return 0;
}
