#include<iostream>
using namespace std;
int main(){
  long long n;
  cin>>n;
  long long a;
  for(long long i=1;i*i<=n;i++){
    if(n%i==0)a=i;
  }
  long long ans=a+n/a-2;
  printf("%lld\n",ans);
}
