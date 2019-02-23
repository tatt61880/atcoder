#include <iostream>
#include <cstring>
using namespace std;

bool uni(char *s)
{
	char c = *s;
	while(*s != '\0'){
		if(*s != c) return false;
		s++;
	}
	return true;
}

int f(char c, char *s)
{
	char str[101];
	strcpy(str, s);
	int len = strlen(str);
	int ret = 0;

	while(!uni(str)){
		ret++;
		len--;
		for(int i = 0;
 i < len; i++){
			if(str[i + 1] == c) str[i] = c;
		}
		str[len] = '\0';
	}
	return ret;
}

int main(int n)
{
	char s[101];
	cin >> s;

	int ans = 1000;
	for(char c = 'a'; c <= 'z'; c++){
		int num = f(c, s);
		if(num < ans) ans = num;
	}
	cout << ans << endl;
	return 0;
}
