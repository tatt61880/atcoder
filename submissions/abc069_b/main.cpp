#include <iostream>
#include <string>

int main(void)
{
 std::string str;
 std::cin >> str;
 std::cout << str[0] << (str.size() - 2) << str[str.size() - 1] << std::endl;
 return 0;
}