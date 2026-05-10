#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int L, X, Y, S, D;
	cin >> L >> X >> Y >> S >> D;
	D += L - S;
	D %= L;
	double ans = (double)D / (X + Y);
	if(Y > X){
		ans = min(ans, (double)(L - D) / (Y - X));
	}
	printf("%.10f\n", ans);
	return 0;
}
