#include <iostream>
#include <string>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	string w;
	cin >> w;
	int count[26] = {0};
	Rep(i, w.size()){
		count[w[i] - 'a']++;
	}
	Rep(i, 26){
		if(c
ount[i] % 2){
			PrintLn("No");
			return 0;
		}
	}
	PrintLn("Yes");
	return 0;
}
