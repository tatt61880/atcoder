#include <iostream>
#include <string>
#include <set>
int main()
{
	std::string str;
	std::cin >> str;
	std::set<char> s;
	for(int i = 0; i < str.size(); i++){
		s.insert(str[i]);
	}
	std::cout << ((s.size() == str.size()) ? "yes" : "no") << std::endl;
	return 0;
}
