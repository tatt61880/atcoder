//{{{
#include <bits/stdc++.h>
using namespace std;
#define repX(a,b,c,x,...) x
#define repN(a) repX a
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop))(__VA_ARGS__)
#define rrep(...) repN((__VA_ARGS__,rrep3,rrep2))(__VA_ARGS__)
#define loop(n) rep2(i_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep3(i,begin,end) for(int i=(int)(begin-1),i##_end=(int)(end);i>=i##_end;--i)
#define foreach(x,a) for(auto&x:a)
using ll=long long;
const ll mod=(ll)1e9+7;
//}}}

struct UnionFind{
  vector<int> parents;
  UnionFind(int n){
    parents.assign(n, -1);
  }

  int root(int x){
    if(parents[x] < 0) return x;
    else return parents[x] = root(parents[x]);
  }

  int size(int x){
    return -parents[root(x)];
  }

  bool same(int x, int y){
    return root(x) == root(y);
  }

  bool unite(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(size(x) < size(y)) swap(x, y);
    parents[x] += parents[y];
    parents[y] = x;
    return true;
  }
};

int A[100000];
int B[100000];
ll diff;
ll ans[100000];

int main(){
  ll N, M;
  cin >> N >> M;
  rep(i, M){
    cin >> A[i];
    cin >> B[i];
    A[i]--;
    B[i]--;
  }

  UnionFind uni(N);

  rrep(i, M){
    if(i == M - 1){
      ans[i] = (ll)N * (N - 1) / 2;
    }else{
      ans[i] = ans[i + 1] - diff;
    }
    int a = A[i];
    int b = B[i];
    if(uni.same(a, b)){
      diff = 0;
    }else{
      int sizeA = uni.size(a);
      int sizeB = uni.size(b);
      uni.unite(a, b);
      diff = (long long)sizeA * sizeB;
    }
  }
  rep(i, M){
    cout << ans[i] << endl;
  }
  return 0;
}
