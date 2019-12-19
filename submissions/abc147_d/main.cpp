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
public:
  u64 a;
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
template <std::uint_fast64_t Mod>
ostream& operator<<(ostream& os, const modint<Mod>& m){ return os << m.a; }
const ll mod=(ll)1e9+7;
using mint = modint<mod>;
//}}}

const int kMaxBit = 64;
int bit0[kMaxBit];
int bit1[kMaxBit];

int main(){
  int N = in();
  vector<ll> A = in(N);

  mint ans = 0;
  rep(i, N){
    rep(b, kMaxBit){
      bit1[b] += ((A[i] >> b) & 1);
    }
  }
  rep(b, kMaxBit){
    bit0[b] = N - bit1[b];
  }

  rep(b, kMaxBit){
    ans += (1LL << b) % mod * bit0[b] % mod * bit1[b];
  }
  cout << ans << endl;
  return 0;
}
