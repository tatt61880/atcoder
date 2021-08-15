#include <iostream>
#include <cstdio>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (n); i++)

int main(void)
{
	int n;
	cin >> n;
	int a1;
	cin >> a1;
	int an;
	Rep(i, n - 1){
		cin >> an;
	}
	printf("%.5f\n", (double)(an - a1) / (n - 1));
	return 0;
}
