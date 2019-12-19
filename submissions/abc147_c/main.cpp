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

class in {
  int n;
public:
  in() {}
  in(int n_) : n(n_){};
  template <class T> operator T() { T ret; cin >> ret; return ret; }
  template <class T> operator vector<T>() { vector<T> ret(n); for (int i = 0; i < n; i++) cin >> ret[i]; return ret; }
};

template <std::uint_fast64_t Mod> class modint {
  using u64 = std::uint_fast64_t;
  u64 a;
  friend ostream& operator<<(ostream& os, const modint& m);
public:
  constexpr modint(const u64 x = 0) noexcept : a(x % Mod) {}
  constexpr u64 val() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept { return modint(*this) += rhs; }
  constexpr modint operator-(const modint rhs) const noexcept { return modint(*this) -= rhs; }
  constexpr modint operator*(const modint rhs) const noexcept { return modint(*this) *= rhs; }
  constexpr modint operator/(const modint rhs) const noexcept { return modint(*this) /= rhs; }
  constexpr bool operator==(const modint rhs) const noexcept { return modint(*this).val() == rhs.val(); }
  modint &operator+=(const modint rhs) noexcept { a += rhs.a; if (a >= Mod) a -= Mod; return *this; }
  modint &operator-=(const modint rhs) noexcept { if (a < rhs.a) a += Mod; a -= rhs.a; return *this; }
  modint &operator*=(const modint rhs) noexcept { a = a * rhs.a % Mod; return *this; }
  modint &operator/=(modint rhs) noexcept { u64 exp = Mod - 2; while (exp) { if (exp % 2) *this *= rhs; rhs *= rhs; exp /= 2; } return *this; }
};
const ll mod=(ll)1e9+7;
using mint = modint<mod>;
ostream& operator<<(ostream& os, const mint& m){ return os << m.a; }
//}}}

int x[15][15];
int y[15][15];

int main(){
  int N = in();
  vector<int> A(N);
  rep(i, N){
    A[i] = in();
    rep(j, A[i]){
      x[i][j] = in();
      x[i][j]--;
      y[i][j] = in();
    }
  }

  int ans = 0;
  rep(n, 1 << N){
    int cnt = 0;
    vector<int> a(N);
    rep(i, N){
      if((n >> i) & 1){
        cnt++;
        a[i] = 1;
      }else{
        a[i] = 0;
      }
    }
    rep(i, N){
      if(a[i]){
        rep(j, A[i]){
          int X = x[i][j];
          int Y = y[i][j];
          if(a[X] != Y) goto F;
        }
      }
    }
    ans = max(ans, cnt);
F:;
  }
  cout << ans << endl;
  return 0;
}
