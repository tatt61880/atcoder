#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
int a,b,c,d;
cin>>a>>b>>c>>d;
cout<<abs(a-c)+abs(b-d)+1<<endl;
return 0;
}