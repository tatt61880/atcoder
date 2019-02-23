#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	string str[50];
	for(int i = 0; i < N; i++){
		cin >> str[i];
	}
	string str2[50*49];
	int x=0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == j) continue;
			str2[x++] = str[i] + str[j];
		}
	}
	string ans = str2[0];
	for(int i = 1; i < x; i++){
		if(str2[i] < ans) ans = str2[i];
	}
	cout << ans << endl;
	return 0;
}

