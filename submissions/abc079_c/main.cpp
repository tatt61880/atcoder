#include <iostream>
#include <string>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(){
	string s;
	cin >> s;
	int a = s[0] - '0';
	int b = s[1] - '0';
	int c = s[2] - '0';
	int d = s[3] - '0';
	Rep(i, 2) Rep(j, 2) Rep(k, 2){
		int ans = a;
		ans += b * (1 - 2 * i);
		ans += c * (1 - 2 * j);
		ans += d * (1 - 2 * k);
		if(ans == 7){
			cout << a << "+-"[i]
				 << b << "+-"[j]
				 << c << "+-"[k]
				 << d << "=7" << endl;
			return 0;
		}
	}
	return 0;
}
