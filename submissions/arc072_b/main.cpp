#include <iostream>
using namespace std;
typedef long long ll;
#if 0
蜷郁ｨ・
0,0 L
蜷郁ｨ・
1,0 L
蜷郁ｨ・
2,0 W
1,1 L
蜷郁ｨ・
3,0 W
2,1 L
蜷郁ｨ・
4,0 W
3,1 W
2,2 L
蜷郁ｨ・
5,0 W
4,1 W
3,2 L
蜷郁ｨ・
6,0 W
5,1 W
4,2 W
3,3 L
#endif
int main(void)
{
	ll X, Y;
	cin >> X >> Y;
	if(X - Y == 0 || X - Y == -1 || X - Y == 1){
		cout << "Brown" << endl;
	}else{
		cout << "Alice" << endl;
	}
	return 0;
}
