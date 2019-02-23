#include <stdio.h>

int N, M, L;
int calcNum(int a, int b, int c){
	return (N / a) * (M / b) * (L / c);
}

int main(void)
{
	scanf("%d%d%d", &N, &M, &L);
	int P, Q, R;
	scanf("%d%d%d", &P, &Q, &R);

	int max = 0;
	int n;
	n = calcNum(P, Q, R);
	if(n > max) max = n;
	n = calcNum(P, R, Q);
	if(n > max) max = n;
	n = calcNum(Q, P, R);
	if(n > max) max = n;
	n = calcNum(Q, R, P);
	if(n > max) max = n;
	n = calcNum(R, Q, P);

	if(n > max) max = n;
	n = calcNum(R, P, Q);
	if(n > max) max = n;
	printf("%d\n", max);
	
	return 0;
}
