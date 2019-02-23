#include <iostream>
#include <string>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	string S;
	cin >> S;
	S += "x";
	unsigned int count = 0;
	unsigned int ans = 0;
	Rep(i, S.size()){
		if(S[i] == '2' && S[i+1] == '5'){
			count++;
			i++;
		}else{
			ans += count * (count + 1) / 2;
			
count = 0;
		}
	}
	PrintLn(ans);
	return 0;
}
