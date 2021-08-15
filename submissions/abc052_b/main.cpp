#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int x = 0;
	int N;
	cin >> N;
	char S[101];
	cin >> S;

	int max = 0;
	Rep(i, N){
		if(S[i] == 'I'){
			x++;
		}else{
			x--;
		}
		if(x > max){
			max = x;
		}
	}
	PrintLn(max);

	return 0;
}
