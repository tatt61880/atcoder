#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define NUM_MAX 1000
int num[NUM_MAX+1] = {1};
void test(int n){
	printf("? %d\n", n); fflush(stdout);
	char judge[2]; scanf("%s", judge);
	if(judge[0]=='Y'){
		for(int j=1; j<=NUM_MAX;j++) if(j%n!=0) num[j]=1;
	}else{
		for(int j=1; j<=NUM_MAX;j++) if(j%n==0) num[j]=1;
	}
}

using namespace std;
int main(void)
{
	int p=2;
	for(int i=0; 
i<199; i++){
		for(;p<NUM_MAX;p++){
			bool f=true;
			for(int q=2; q<p; q++){
				if(p%q==0){
					f=false;
					break;
				}
			}
			if(f){
				test(p);
				p++;
				break;
			}else{
				continue;
			}
		}
	}
	for(int j=1; j<=NUM_MAX;j++){
		if(num[j]==0) test(j);
	}
	for(int j=1; j<=NUM_MAX;j++){
		if(num[j]==0){
			printf("! %d\n", j); fflush(stdout);
			break;
		}
	}
	return 0;
}
