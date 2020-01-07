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
#define each(x,a) for(auto&x:a)

struct IoSetup{
  IoSetup(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  };
} ioSetup;

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

template<class T>inline void Sort(T&a) { sort(a.begin(), a.end()); }
template<class T, class Compare>inline void Sort(T&a, Compare comp) { sort(a.begin(), a.end(), comp); }
template<class T>inline void rSort(T&a) { sort(a.rbegin(), a.rend()); }
template<class T>inline void Reverse(T&a) { reverse(a.begin(), a.end()); }
template<class T>inline T Sum(vector<T>&a){return accumulate(a.begin(), a.end(), (T)0);}
template<class T>inline T max(vector<T>&a){return *max_element(a.begin(), a.end());}
template<class T>inline T min(vector<T>&a){return *min_element(a.begin(), a.end());}

template<class T,class U>inline bool chmax(T&a,const U&b){return(b>a)?(a=b,true):false;}
template<class T,class U>inline bool chmin(T&a,const U&b){return(b<a)?(a=b,true):false;}

ll gcd(const ll a, const ll b){return b ? gcd(b, a % b) : a;}
ll lcm(const ll a, const ll b){return a / gcd(a, b) * b;}

class in {
  int n;
public:
  in() {n=-1;}
  in(int n_) : n(n_){};
  template <class T> operator T() { T ret; cin >> ret; return ret; }
  template <class T> operator vector<T>() {assert(n >= 0); vector<T> ret(n); for(int i=0;i<n;++i) cin>>ret[i]; return ret; }
};

template<class T> void print(const T& a){ cout << a; }
int out(){ cout<<'\n'; return 0; }
template<class T> int out(const T& t){ print(t); cout<<'\n'; return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); cout << " "; out(tail...); return 0; }

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
template <std::uint_fast64_t Mod> ostream& operator<<(ostream& os, const Modular<Mod>& m){ return os << m.a; }

const double pi=acos(-1);
const double eps = 1e-9;
const ll inf = 1001001001;
const ll mod=(ll)1e9+7;
using mint = Modular<mod>;

//}}}

int main(){
  int n = in();
  map<string, ll> mp;
  rep(i, n){
    string s = in();
    Sort(s);
    mp[s]++;
  }
  ll ans = 0;
  each(x, mp){
    ans += x.second * (x.second - 1) / 2;
  }
  out(ans);
}
