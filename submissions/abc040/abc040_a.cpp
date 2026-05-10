#include<iostream>
using namespace std;
int main()
{
 int a,b;
 cin>>b>>a;
 b-=a;
 a-=1;
 cout << (a<b?a:b) <<endl;
 return 0;
}