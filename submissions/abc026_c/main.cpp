#include <stdio.h>
int p[20][20];
int salary[20] = {0};
int calc_salary(int id)
{
	if(salary[id]) return salary[id];
	if(p[id][0] == -1){
		return salary[id] = 1;
	}
	int max = calc_salary(p[id][0]);
	int min = calc_salary(p[id][0]);
	int j = 1;
	while(p[id][j] >= 0){
		if(calc_salary(p[id][j]) > max) max = calc_salary(p[id][j]);
		if(calc_salary(p[id][j]) < min) min = calc_salary(p[id][j]);
		j++;
	}
	return salary[id] = max + min + 1;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			p[i][j] = -1;
		}
	}
	for(int i=1; i<N; i++){
		int j=0;
		int B;
		scanf("%d", &B);
		B--;
		while(p[B][j] >= 0) j++;
		p[B][j] = i;
	}
#if 0
	for(int i=0; i<N; i++){
		int j = 0;
		while(p[i][j] != -1){
			printf("%d ", p[i][j]);
			j++;
		}
		puts("");
	}
#endif
	printf("%d\n", calc_salary(0));
	return 0;
}
