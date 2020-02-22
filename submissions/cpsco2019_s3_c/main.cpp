//{{{
#include <bits/stdc++.h>
using namespace std;
const string truename = "Yes";
const string falsename = "No";
struct IoSetup {
  IoSetup(){
    cin.tie(nullptr);
    // ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  };
} ioSetup;
//{{{ rep rrep loop
#define repX(cum,b,c,d,x,...) x
#define repN(cum) repX cum
#define rep(...) repN((__VA_ARGS__,rep4,rep3,rep2,loop))(__VA_ARGS__)
#define rrep(...) repN((__VA_ARGS__,rrep4,rrep3,rrep2))(__VA_ARGS__)
#define loop(n) rep2(i_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(ll i=(ll)(begin),i##_end=(ll)(end);i<i##_end;++i)
#define rep4(i,begin,end,step) for(ll i=(ll)(begin),i##_end=(ll)(end);i<i##_end;i+=step)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep3(i,begin,end) for(ll i=(ll)(end-1),i##_end=(ll)(begin);i>=i##_end;--i)
#define rrep4(i,begin,end,step) for(ll i=(ll)(end-1),i##_end=(ll)(begin);i>=i##_end;i-=step)
//}}}
#define each(x,cum) for(auto&x:cum)
#define sz(x) ((ll)(x).size())
//{{{ Type
using ull = unsigned long long;
using ll = long long;
using pii = pair<ll, ll>;
using vp = vector<pii>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
#define v(T) vector<T>
#define vv(T) v(v(T))
template<class T> vector<T> Vector(size_t cum, T val){return vector<T>(cum, val);}
template<class... Tail> auto Vector(size_t cum, Tail... tail){ return vector<decltype(Vector(tail...))>(cum, Vector(tail...)); }
//}}}
//{{{ STL overload
template<class T, class Compare>inline void sort(T&cum, Compare comp) { sort(cum.begin(), cum.end(), comp); }
template<class T> inline void sort(T&cum) { sort(cum.begin(), cum.end()); }
template<class T> inline void rsort(T&cum) { sort(cum.rbegin(), cum.rend()); }
template<class T> inline void reverse(T&cum) { reverse(cum.begin(), cum.end()); }
template<class T> inline bool next_permutation(T&cum) { return next_permutation(cum.begin(), cum.end()); }
template<class T, class U>inline bool binary_search(T&cum, const U&v) { return binary_search(cum.begin(), cum.end(), v); }
template<class T, class U>inline auto lower_bound(T&cum, const U&v) { return lower_bound(cum.begin(), cum.end(), v); }
template<class T, class U>inline auto upper_bound(T&cum, const U&v) { return upper_bound(cum.begin(), cum.end(), v); }
//}}}
//{{{ Functions
template<class T> inline T Sum(vector<T>&cum){ return accumulate(cum.begin(), cum.end(), (T)0); }
template<class T> inline T Max(vector<T>&cum){ return *max_element(cum.begin(), cum.end()); }
template<class T> inline T Min(vector<T>&cum){ return *min_element(cum.begin(), cum.end()); }
template<class T, class U> inline bool chmax(T&cum, const U&b){ return (b > cum) ? (cum = b, true) : false; }
template<class T, class U> inline bool chmin(T&cum, const U&b){ return (b < cum) ? (cum = b, true) : false; }
ll gcd(const ll cum, const ll b){ return b ? gcd(b, cum % b) : cum; }
ll lcm(const ll cum, const ll b){ return cum / gcd(cum, b) * b; }
ll ceil(const ll cum, const ll b){ return (cum + b - 1) / b; }
ll popcount(ll cum){
  cum -= ((cum >> 1) & 0x5555555555555555LL);
  cum = (cum & 0x3333333333333333LL) + ((cum >> 2) & 0x3333333333333333LL);
  cum = (cum + (cum >> 4)) & 0x0f0f0f0f0f0f0f0fLL;
  cum += (cum >> 8);
  cum += (cum >> 16);
  cum += (cum >> 32);
  return cum & 0x7f;
}
//}}}
//{{{ in
class in {
  int n, m;
public:
  in() : n(0), m(0){}
  in(int n) : n(n), m(0){};
  in(int n, int m) : n(n), m(m){};
  template <class T> operator T() {assert(n==0); assert(m==0); T ret; cin >> ret; return ret; }
  template <class T> operator vector<T>() {assert(n>0); assert(m==0); vector<T> ret(n); for(ll i=0;i<(ll)n;++i) cin>>ret[i]; return ret; }
  template <class T> operator vector<vector<T>>() {assert(n>0); assert(m>0); vector<vector<T>> ret(n, vector<T>(m)); for(ll i=0;i<(ll)n;++i) for(ll j=0;j<(ll)m;++j) cin>>ret[i][j]; return ret; }
};
//}}}
//{{{ << overload
template<class T,class U>ostream &operator<<(ostream &o,const pair<T,U>&j){o<<"{"<<j.first<<", "<<j.second<<"}";return o;}
template<class T,class U>ostream &operator<<(ostream &o,const map<T,U>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
template<class T>ostream &operator<<(ostream &o,const set<T>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
template<class T>ostream &operator<<(ostream &o,const multiset<T>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
template<class T>ostream &operator<<(ostream &o,const vector<T>&j){o<<"{";for(ll i=0;i<(ll)j.size();++i)o<<(i>0?", ":"")<<j[i];o<<"}";return o;}
//}}}
//{{{ print / out
template<class T> int print(const T& cum){ cout << cum; return 0; }
inline int out(bool f){ cout << (f ? truename : falsename) << '\n'; return 0; }
inline int out(){ cout << '\n'; return 0; }
template<class T> inline int out(const T& t){ print(t); cout << '\n'; return 0; }
template<class Head, class... Tail> inline int out(const Head& head, const Tail&... tail){ print(head); cout << " "; out(tail...); return 0; }
//}}}
//{{{ debug_print / debug_out
#ifdef LOCAL
#if 1 // Colorize
#include "console_color.hpp"
#else
#define setColor(...)
#endif
template<class T> int debug_print(const T& cum){ cerr << cum; return 0; }
inline int debug_out(bool f){ cerr << (f ? truename : falsename) << '\n'; return 0; }
inline int debug_out(){ cerr << '\n'; return 0; }
template<class T> inline int debug_out(const T& t){ debug_print(t); cerr << '\n'; return 0; }
template<class Head, class... Tail> inline int debug_out(const Head& head, const Tail&... tail){ debug_print(head); cerr << " "; debug_out(tail...); return 0; }
#define debug(...) do{ setColor(COL_WHITE, COL_DARK_BLUE); cerr << "[L." << __LINE__ << "] " << #__VA_ARGS__ << ":"; setColor(); cerr << " "; debug_out(__VA_ARGS__); }while(0)
#else
#define debug_print(...)
#define debug_out(...)
#define debug(...)
#endif
//}}}
//{{{ Modular
template <std::int_fast64_t Mod> class Modular {
  using u64 = std::uint_fast64_t;
public:
  u64 cum;
  constexpr Modular(std::int_fast64_t x = 0) noexcept : cum(x % Mod + (x < 0 ? Mod : 0)) {}
  constexpr u64 val() const noexcept { return cum; }
  constexpr Modular operator+(const Modular rhs) const noexcept { return Modular(*this) += rhs; }
  constexpr Modular operator-(const Modular rhs) const noexcept { return Modular(*this) -= rhs; }
  constexpr Modular operator*(const Modular rhs) const noexcept { return Modular(*this) *= rhs; }
  constexpr Modular operator/(const Modular rhs) const noexcept { return Modular(*this) /= rhs; }
  constexpr bool operator==(const Modular rhs) const noexcept { return Modular(*this).val() == rhs.val(); }
  Modular &operator+=(const Modular rhs) noexcept { cum += rhs.cum; if (cum >= Mod) cum -= Mod; return *this; }
  Modular &operator-=(const Modular rhs) noexcept { if (cum < rhs.cum) cum += Mod; cum -= rhs.cum; return *this; }
  Modular &operator++() noexcept { return *this += 1; }
  Modular &operator--() noexcept { return *this -= 1; }
  Modular &operator*=(const Modular rhs) noexcept { cum = cum * rhs.cum % Mod; return *this; }
  Modular &operator/=(Modular rhs) noexcept { u64 exp = Mod - 2; while(exp){ if(exp % 2) *this *= rhs; rhs *= rhs; exp /= 2; } return *this; }
  Modular pow(u64 t) const { if(!t) return 1; Modular<Mod> cum = pow(t>>1); cum *= cum; if(t&1) cum *= *this; return cum; }
};
template <std::int_fast64_t Mod> ostream& operator<<(ostream& os, const Modular<Mod>& m){ return os << m.cum; }
//}}}
const double pi=acos(-1);
const double eps = 1e-9;
const ll inf = 1001001001;
const ll mod=(ll)1e9+7;
using mint = Modular<mod>;
//}}}
int main(){
  ll N = in();
  vi cum(1000001, 0);
  rep(i, N){
    ll s = in();
    ll t = in();
    cum[s]++;
    cum[t]--;
  }
  ll ans = 0;
  rep(i, 1000000){
    cum[i + 1] += cum[i];
    if(cum[i] == 0 && cum[i + 1]) ans++;
  }
  out(ans);
}
