#include <iostream>
#include <string>
int main(void)
{
	std::string S;
	std::cin >> S;
	S[S.size() - 1]++;
	std::cout << S << std::endl;
	return 0;
}
