#include <iostream>
#include <algorithm>
using namespace std;
#define Print(X) cout << X
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)n; ++i)
#define For(i, a, b) for(int i = a; i < (int)b; ++i)
int main(void)
{
	int a, b;
	cin >> a >> b;
	if(a > b) swap(a, b);
	int count = 0;
	while(a != b){
		count++;
		if(b >= a + 8){
			b -= 10;
		}else if(b >= a + 4){
			b -= 5;
		}else{
			b--;
		}
		if(a > b) swap(a, b);
	}
	PrintLn(count);
	return 0;
}
