#include <iostream>
int main()
{
	int n;
	std::cin >> n;
	int min = 1e9;
	int max = -1e9;
	for(int i = 0; i < n; i++){
		int a;
		std::cin >> a;
		if(a < min) min = a;
		if(a > max) max = a;
	}
	std::cout << (max - min) << std::endl;
	return 0;
}
