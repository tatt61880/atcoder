#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define printLn(X) cout << X << endl
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(){
	int N, Y;
	cin >> N >> Y;
	rep(i, N + 1){
		rep(j, N - i + 1){
			int k = N - i -
 j;
			if(i * 10000 + j * 5000 + k * 1000 == Y){
				printLn(i << " " << j << " " << k);
				return 0;
			}
		}
	}
	printLn("-1 -1 -1");
	return 0;
}
