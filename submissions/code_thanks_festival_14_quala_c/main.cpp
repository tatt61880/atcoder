#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(void)
{
 int n,m;
 cin>>n>>m;
 int p[100];
 rep(i,n) cin>>p[i];
 int s,sum=0;
 rep(i,m) cin>>s, sum+=p[s-1];
 cout<<sum<<endl;
 return 0;
}