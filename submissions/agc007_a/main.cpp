#include <iostream>
#include <string>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	int H, W;
	cin >> H >> W;
	int count = 0;
	Rep(i, H){
		string str;
		cin >> str;
		Rep(j, str.length()){
			if(str[j] == '#') count++;
		}
	}
	PrintLn(((count == H + W - 1) ? "Possible" : "Impossible"));
	return 0;
}
