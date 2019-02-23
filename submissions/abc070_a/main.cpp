#include <iostream>
#include <cstdlib>
using namespace std;

#define PrintLn(X) cout << X << endl
int main(void)
{
	int N;
	cin >> N;
	if(N / 100 == N % 10){
		PrintLn("Yes");
	}else{
		PrintLn("No");
	}
	return 0;
}
