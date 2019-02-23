//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,b
egin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const int MOD = 1e9+7;
//}}}

int path[8][8] = {0};

int f(int arr[], int n){
  int start, end;
  start = 0;
  rep(i, n){
    end = arr[i];
    if(!path[start][end]) return 0;
    start = end;
  }
  return 1;
}

int main(){
  int N, M;
  cin >> N >> M;

  rep(i, M){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a][b] = 1;
    path[b][a] = 1;
  }
  int arr[8] = {0};
  rep(i, 1, N){
    arr[i - 1] = i;
  }

  int ans = 0;
  do{
    ans += f(arr, N - 1);
  }while(next_permutation(arr, arr + N - 1));
  cout << ans << endl;
  return 0;
}
