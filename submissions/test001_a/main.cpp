#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (n); i++)
int main(void)
{
	int N;
	cin >> N;
	string S;
	cin >> S;
	int mn = N;
	int mx = 0;
	Rep(x, 4){
		int count = 0;
		Rep(i, N){
			if(S[i] == x + '1') count++;
		}
		mn = min(mn, count);
		mx = max(mx, count);
	}
	cout << mx << " " << mn << endl;
	return 0;
}
