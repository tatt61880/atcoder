#include<iostream>
#include<string>
using namespace std;

int main(void){
 string str;
 cin >> str;
 int n=0,w=0,s=0,e=0;
 for(auto x:str){
  switch(x){
  case 'N': n=1; break;
  case 'W': w=1; break;
  case 'S': s=1; break;
  case 'E': e=1; break;
  }
 }
 cout << (!(n^s || w^e) ? "Yes" : "No") << endl;
 return 0;
}
