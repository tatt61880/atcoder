//{{{
#include <bits/stdc++.h>
using namespace std;

#define repX(a,b,c,x,...) x
#define repN(a) repX a
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop))(__VA_ARGS__)
#define rrep(...) repN((__VA_ARGS__,rrep3,rrep2))(__VA_ARGS__)
#define loop(n) rep2(i_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(ll i=(ll)(begin),i##_end=(ll)(end);i<i##_end;++i)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep3(i,begin,end) for(ll i=(ll)(end-1),i##_end=(ll)(begin);i>=i##_end;--i)
#define each(x,a) for(auto&x:a)
#define sz(x) ((ll)(x).size())

struct IoSetup{
  IoSetup(){
    cin.tie(nullptr);
    // ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  };
} ioSetup;

using ull=unsigned long long;
using ll=long long;
using pii=pair<ll, ll>;
using vp=vector<pii>;
using vs=vector<string>;
using vi=vector<ll>;
using vvi=vector<vi>;
#define v(T) vector<T>
#define vv(T) v(v(T))

template<class T,class U>ostream &operator<<(ostream &o,const pair<T,U>&j){o<<"{"<<j.first<<", "<<j.second<<"}";return o;}
template<class T,class U>ostream &operator<<(ostream &o,const map<T,U>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
template<class T>ostream &operator<<(ostream &o,const set<T>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
template<class T>ostream &operator<<(ostream &o,const multiset<T>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
template<class T>ostream &operator<<(ostream &o,const vector<T>&j){o<<"{";for(ll i=0;i<(ll)j.size();++i)o<<(i>0?", ":"")<<j[i];o<<"}";return o;}

template<class T, class Compare>inline void sort(T&a, Compare comp) { sort(a.begin(), a.end(), comp); }
template<class T> inline void sort(T&a) { sort(a.begin(), a.end()); }
template<class T> inline void rsort(T&a) { sort(a.rbegin(), a.rend()); }
template<class T> inline void reverse(T&a) { reverse(a.begin(), a.end()); }
template<class T> inline bool next_permutation(T&a) { return next_permutation(a.begin(), a.end()); }
template<class T, class U>inline bool binary_search(T&a, const U&v) { return binary_search(a.begin(), a.end(), v); }
template<class T, class U>inline auto lower_bound(T&a, const U&v) { return lower_bound(a.begin(), a.end(), v); }
template<class T, class U>inline auto upper_bound(T&a, const U&v) { return upper_bound(a.begin(), a.end(), v); }
template<class T> inline T Sum(vector<T>&a){ return accumulate(a.begin(), a.end(), (T)0); }
template<class T> inline T Max(vector<T>&a){ return *max_element(a.begin(), a.end()); }
template<class T> inline T Min(vector<T>&a){ return *min_element(a.begin(), a.end()); }

template<class T, class U> inline bool chmax(T&a, const U&b){ return (b > a) ? (a = b, true) : false; }
template<class T, class U> inline bool chmin(T&a, const U&b){ return (b < a) ? (a = b, true) : false; }

ll gcd(const ll a, const ll b){ return b ? gcd(b, a % b) : a; }
ll lcm(const ll a, const ll b){ return a / gcd(a, b) * b; }
ll ceil(const ll a, const ll b){ return (a + b - 1) / b; }

class in {
  int n, m;
public:
  in() : n(0),m(0){}
  in(int n_) : n(n_),m(0){};
  in(int n_, int m_) : n(n_),m(m_){};
  template <class T> operator T() {assert(n==0); assert(m==0); T ret; cin >> ret; return ret; }
  template <class T> operator vector<T>() {assert(n>0); assert(m==0); vector<T> ret(n); for(ll i=0;i<(ll)n;++i) cin>>ret[i]; return ret; }
  template <class T> operator vector<vector<T>>() {assert(n>0); assert(m>0); vector<vector<T>> ret(n, vector<T>(m)); for(ll i=0;i<(ll)n;++i) for(ll j=0;j<(ll)m;++j) cin>>ret[i][j]; return ret; }
};

template<class T> void print(const T& a){ cout << a; }
inline int out(){ cout << '\n'; return 0; }
template<class T> inline int out(const T& t){ print(t); cout<<'\n'; return 0; }
template<class Head, class... Tail> inline int out(const Head& head, const Tail&... tail){ print(head); cout << " "; out(tail...); return 0; }

#ifdef LOCAL
#include "console_color.hpp"
template<class T> void debug_print(const T& a){ cerr << a; }
inline void dump(){ setColor(); cerr << " \n"; }
template<class T> inline void dump(const T& t){ debug_print(t); setColor(); cerr << " \n"; }
template<class Head,class... Tail> inline void dump(const Head& head, const Tail&... tail){ setColor(COL_WHITE, COL_DARK_YELLOW); debug_print(head); cerr<<" "; dump(tail...); }
#define debug(...) do{ setColor(COL_WHITE, COL_DARK_BLUE); cerr<<"[L."<<__LINE__<<"] "<<#__VA_ARGS__<<": "; setColor(COL_WHITE, COL_DARK_YELLOW); dump(__VA_ARGS__); }while(0)
#else
#define dump(...)
#define debug(...)
#endif

template<class T> vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Tail> auto make_vector(size_t a, Tail... tail){ return vector<decltype(make_vector<T>(tail...))>(a, make_vector<T>(tail...)); }
#define Vector make_vector<ll>

template <std::int_fast64_t Mod> class Modular {
  using u64 = std::uint_fast64_t;
public:
  u64 a;
  constexpr Modular(std::int_fast64_t x = 0) noexcept : a(x % Mod + (x < 0 ? Mod : 0)) {}
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
  Modular &operator/=(Modular rhs) noexcept { u64 exp = Mod - 2; while(exp){ if(exp % 2) *this *= rhs; rhs *= rhs; exp /= 2; } return *this; }
};
template <std::int_fast64_t Mod> ostream& operator<<(ostream& os, const Modular<Mod>& m){ return os << m.a; }

const double pi=acos(-1);
const double eps = 1e-9;
const ll inf = 1001001001;
const ll mod=(ll)1e9+7;
using mint = Modular<mod>;
//}}}

int main(){
  ll N = in();
  vi A = in(N);
  ll mn = A[0];

  ll ans = 0;
  rep(i, N){
    if(A[i] <=  mn){
      ans++;
      mn = A[i];
    }
  }
  out(ans);
}
