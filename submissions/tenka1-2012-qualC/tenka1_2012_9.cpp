#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl

int main(void)
{
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 2; i < n; i++){
		bool f = true;
		for(int j = 2; j * j <= i; j++){
			if(i % j == 0) f = false;
		}
		if(f) ans++;
	}
	PrintLn(ans);
	return 0;
}
