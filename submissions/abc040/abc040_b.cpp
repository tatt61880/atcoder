#include<iostream>
using namespace std;
int main(){
 int n;
 cin>>n;
 int min=n;
 for(int i=1; i<=n/i; i++){
  int s=n/i*i;
  int d=n/i-i;
  int x=n-s+d;
  if(x<min)min=x;
 }
 cout<<min<<endl;
 return 0;
}