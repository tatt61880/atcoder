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
#define rrep2(i,n) rrep3(i,0,n)
#define rrep3(i,begin,end) for(int i=(int)(end-1),i##_end=(int)(begin);i>=i##_end;--i)
#define foreach(x,a) for(auto&x:a)
using ll=long long;

template<class T,class U>ostream &operator<<(ostream &o,const pair<T,U>&j){o<<"{"<<j.first<<", "<<j.second<<"}";return o;}
template<class T,class U>ostream &operator<<(ostream &o,const map<T,U>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
template<class T>ostream &operator<<(ostream &o,const set<T>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
template<class T>ostream &operator<<(ostream &o,const multiset<T>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
template<class T>ostream &operator<<(ostream &o,const vector<T>&j){o<<"{";for(int i=0;i<(int)j.size();++i)o<<(i>0?", ":"")<<j[i];o<<"}";return o;}
#ifdef LOCAL
inline void dump(void){cerr<<endl;}
template<class Head,class... Tail> inline void dump(Head&& head,Tail&&... tail){cerr<<head<<" ";dump(tail...);}
#define debug(...) do{cerr<<"[L."<<__LINE__<<"]\t"<<#__VA_ARGS__<<"=";dump(__VA_ARGS__);}while(0)
#else
#define dump(...)
#define debug(...)
#endif

template<class T,class U>inline bool chmax(T&a,U b){return(a<b)?(a=b,true):false;}
template<class T,class U>inline bool chmin(T&a,U b){return(a>b)?(a=b,true):false;}
struct IoSetup{
  IoSetup(){
    cin.tie(0); ios::sync_with_stdio(0);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  };
} ioSetup;

class in {
  int n;
public:
  in() {}
  in(int n_) : n(n_){};
  template <class T> operator T() { T ret; cin >> ret; return ret; }
  template <class T> operator vector<T>() { vector<T> ret(n); for (int i = 0; i < n; i++) cin >> ret[i]; return ret; }
};

template<class T> void print(const T& a){ cout << a; }
void out(){ putchar('\n'); }
template<class T> void out(const T& t){ print(t); putchar('\n'); }
template<class Head, class... Tail> void out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); }

template <std::uint_fast64_t Mod> class Modular {
  using u64 = std::uint_fast64_t;
public:
  u64 a;
  constexpr Modular(const u64 x = 0) noexcept : a(x % Mod) {}
  constexpr u64 val() const noexcept { return a; }
  constexpr Modular operator+(const Modular rhs) const noexcept { return Modular(*this) += rhs; }
  constexpr Modular operator-(const Modular rhs) const noexcept { return Modular(*this) -= rhs; }
  constexpr Modular operator*(const Modular rhs) const noexcept { return Modular(*this) *= rhs; }
  constexpr Modular operator/(const Modular rhs) const noexcept { return Modular(*this) /= rhs; }
  constexpr bool operator==(const Modular rhs) const noexcept { return Modular(*this).val() == rhs.val(); }
  Modular &operator+=(const Modular rhs) noexcept { a += rhs.a; if (a >= Mod) a -= Mod; return *this; }
  Modular &operator-=(const Modular rhs) noexcept { if (a < rhs.a) a += Mod; a -= rhs.a; return *this; }
  Modular &operator++() noexcept { return *this += 1; }
  Modular &operator--() noexcept { return *this -= 1; }
  Modular &operator*=(const Modular rhs) noexcept { a = a * rhs.a % Mod; return *this; }
  Modular &operator/=(Modular rhs) noexcept { u64 exp = Mod - 2; while (exp) { if (exp % 2) *this *= rhs; rhs *= rhs; exp /= 2; } return *this; }
};
template <std::uint_fast64_t Mod>
ostream& operator<<(ostream& os, const Modular<Mod>& m){ return os << m.a; }

ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

const double pi=acos(-1);
const ll mod=(ll)1e9+7;
using mint = Modular<mod>;
//}}}

int main(){
  int a = in();
  int b = in();
  int x = in();
  double ans;
  if(x <= a * a * b / 2){
    ans = atan(0.5*a*b*b/x);
  }else{
    ans = atan(2.0*(a*a*b-x)/(a*a*a));
  }
  ans *= 180.0/pi;
  out(ans);
  return 0;
}
