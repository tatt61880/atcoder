#include <iostream>
#include <cstdio>
using namespace std;
int main(void)
{
	long long N, K;
	cin >> N >> K;
	long long count = 0;
	count += (K - 1) * (N - K) * 6; //XKY
	count += (K - 1) * 3; //XKK
	count += (N - K) * 3; //KKY
	count += 1; //KKK
	printf("%.15f\n", (double)count / N / N / N);
	return 
0;
}
