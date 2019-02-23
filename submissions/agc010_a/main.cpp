#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int N;
	cin >> N;
	int count = 0;
	Rep(i, N){
		int a;
		cin >> a;
		if(a % 2 == 1){
			count++;
		}
	}
	if(count % 2 == 0){
		PrintLn("YES");
	}else
{
		PrintLn("NO");
	}
	return 0;
}
