#include <iostream>
#include <string>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (n); i++)

int main(void)
{
	int P[10001] = {1};
	int Q[] = {25,39,51,76,163,111,136,128,133,138};
	Rep(q, 10){
		for(int p = 10000; p >= 0; p--){
			if(P[p]){
				if(Q[q] == 136){
					P[p + 136] = 1;
					P[p + 58] = 1;
				}else{
					P[p + Q[q]] = 1;
				}
			}
		}
	}
	Rep(p, 10000){
		if(P[p] == 1) PrintLn(p);

	}
	return 0;
}
