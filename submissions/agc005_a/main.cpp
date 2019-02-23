#include <iostream>
#include <string>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	string X;
	cin >> X;

	int s = 0, t = 0, c = 0;
	int ans = X.size();

	Rep(i, X.size()){
		if(X[i] == 'S'){
			s++;
		}else{
			t++;
		}
		if(X[i] == 'T' && s > 0 && t > 0){
			s--;
			t--;
			ans -= 2;
		}
	}
	PrintLn(ans);
	return 0;
}
