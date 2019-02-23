#include <iostream>
#define PrintLn(X) cout << X << endl
using namespace std;

int main(void)
{
	int N, T, A;
	cin >> N >> T >> A;
	if(T == A){
		PrintLn(((N % (T + 1) == 0) ? "Aoki" : "Takahashi"));
	}else{
		if(T < A){
			if(N <= T){
				PrintLn("Takahashi");
			}else{
				PrintLn(
"Aoki");
			}
		}else{
			PrintLn("Takahashi");
		}
	}
	return 0;
}
