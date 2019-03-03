#include <stdio.h>
#define MAX 10000
int main(void)
{
	int N;
	long long A, B;
	scanf("%d%lld%lld", &N, &A, &B);
	long long S[100000];
	for(int i=0; i<N; i++){
		scanf("%lld", &S[i]);
	}
	long long max = S[0];
	long long min = S[0];
	long long sum = S[0];
	for(int i = 1; i < N; i++){
		if(S[i] > max) max = S[i];
		if(S[i] < min) min = S[i];
		sum += S[i];
	}
	if(max == min){
		puts("-1");
		return 0;
	}
	double P, Q;
	P = (double)B / (max - min);
	Q = (N * A - P * sum) / N;
	//printf("[%d %lld %lf %d]\n", N, A, P, sum);
	printf("%lf %lf\n", P, Q);
	return 0;
}
