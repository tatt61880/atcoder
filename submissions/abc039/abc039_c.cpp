#include <iostream>
#include <cstring>

int main(void)
{
	char s[21];
	std::cin >> s;
	char a[] = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
	int pos[] = {0, 2, 4, 5, 7, 9, 11};
	char ans[7][3] = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};


	for(int i = 0; i < 7; i++){
		if(strncmp(a + pos[i], s, 20) == 0){
			std::cout << ans[i] << std::endl;
		}
	}
	return 0;
}
