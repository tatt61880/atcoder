#include <iostream>
int main(void)
{
 int a, b, c;
 std::cin >> a >> b >> c;
 std::cout << 2 * (a * b + b * c + c * a) << std::endl;
 return 0;
}
