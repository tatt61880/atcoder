#include <iostream>
using namespace std;
typedef long long LL;
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define PrintLn(X) cout << X << endl

int main(void)
{
	int N, R;
	cin >> N >> R;
	char S[100];
	Rep(i, N) cin >> S[i];
	int move = 0;
	int count = 0;
	Rep(i, N){
		if(S[N - i - 1] == '.&#
39;){
			i += R - 1;
			if(move == 0){
				move = N - i - 1;
				if(move < 0) move = 0;
			}
			count++;
		}
	}
	PrintLn(move + count);
	return 0;
}
