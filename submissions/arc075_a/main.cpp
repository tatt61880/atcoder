#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define Rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PrintLn(X) cout << X << endl

typedef long long ll;
int a[100];
int sum[10001] = {0};
int N;

int main(void)
{
	cin >> N;
	Rep(i, N) cin 
>> a[i];
	sum[0] = 1;
	Rep(i, N){
		for(int j = 10000; j >= 0; j--){
			if(sum[j]){
				sum[j + a[i]] = 1;
			}
		}
	}

	for(int i = 10000; i >= 0; i--){
		if(i % 10 != 0 && sum[i]){
			PrintLn(i);
			return 0;
		}
	}
	PrintLn(0);
	return 0;
}
