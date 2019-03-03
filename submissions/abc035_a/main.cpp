#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
int main(void)
{
	int W,H;
	cin >> W >> H;
	if(W * 3 == H * 4){
		PrintLn("4:3");
	}else{
		PrintLn("16:9");
	}
	return 0;
}
