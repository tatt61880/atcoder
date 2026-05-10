#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

long long A[100000];
long long N;

int main(void)
{
	cin >> N;
	long long sum = 0;
	Rep(i, N){
		cin >> A[i];
		sum += A[i];
	}

	if(sum % (N * (N + 1) / 2) != 0){
		PrintLn("NO");
		return 0;
	}
	long long count = sum / (N * (N + 1) / 2);

	Rep(i, N){
		if(A[i] < count){
			PrintLn("NO");
			return 0;
		}
		A[i] += (count % N) * (N - i - 1);
		A[i] %= N;
	}

	Rep(i, N){
		if(A[i] != A[0]){
			PrintLn("NO");
			return 0;
		}
	}
	PrintLn("YES");
	return 0;
}
