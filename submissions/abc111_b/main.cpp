#include <iostream>
using namespace std;

int main()
{
  int N;
  cin >> N;
  for(int i = 999; ; i -= 111){
    if(i < N){
      cout << (i + 111) << endl;
      return 0;
    }
  }
}