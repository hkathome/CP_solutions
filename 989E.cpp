#include <iostream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define ull unsigned long long 
#define lld long double
#define ll long long 
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
#define trav(z,x) for(auto &z:x)
#define deb(x) cerr<<#x<<" "<<x<<"\n";
#define debug2(x,y) cerr<<#x<<" "<<x<<" "<<#y<<" "<<y<<"\n";
#include <chrono>
#include <random>
using namespace std;
const int mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(42);

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

#define n_l '\n'
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: "; cerr << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cerr << to_string(H) << " | "; dbgm(T...); } 
#define dbgm(...) cerr << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cerr << endl
ll expo(ll a, ll b) {
    if (b == 0) {return 1;}
    ll z = expo(a, b / 2); z *= z; z %= mod; if (b % 2 != 0) {z *= a; z %= mod;}
    return z;
}
ll gcd(ll a, ll b) {
    if (a == 0)return b;
    return gcd(b % a, a);
}
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
int n,k;
const int K=2;
const int N = 2e5 + 10;
int base[K];//arr[0][0]=seed arr[0][1]=modulo
int modulo[K];
bool prime(int x)
{
    for(int i = 2; i * 1ll * i <= x; i++)
        if(x % i == 0)
            return false;
    return true;    
}   
int get_base()
{
    int x = rnd() % 10000 + 4444;
    while(!prime(x)) x++;
    return x;
}   
int get_modulo()
{
    int x = rnd() % int(1e9) + int(1e8);
    while(!prime(x)) x++;
    return x;
}   
void generate_hs()
{
    for(int i = 0; i < K; i++)
    {
        base[i] = get_base();
        modulo[i] = get_modulo();
    }
}  

ll get_hash(vector<int>&v,int seed,int modulo) {
    int n = v.size();
    ll val = 0;
    ll p = 1;
    for (int i = 0; i < n; i++) {
        ll val1 = v[i];
        val1 *= p;
        val1 %= modulo;
        p *= (1ll * seed);
        p %= modulo;
        val += val1;
        val %= modulo;
    }
    return val;
}
void check(int req){
    vector<int>v;
    for(int i=1;i<=n;i++){
        v.pb(i);
    }
    vector<vector<int>>vv;
    do{
        vv.pb(v);
    }while(next_permutation(all(v)));
    dbg(vv);
    for(int i=0;i<vv.size();i++){
        for(int j=i+1;j<vv.size();j++){
            bool f=true;
            for(int k=0;k<n;k++){
                int sum=(vv[i][k]+vv[j][k]+k+1);
                if(sum!=req){
                    f=false;
                    break;
                }
            }
            if(f){
                dbg(vv[i]);
                dbg(vv[j]);
                //return;
            }
        }
    }
}
int fac(int x){
    if(x==1){
        return 1;
    }
    return x*fac(x-1);
}
void print(vector<int>&v){
    trav(z,v){
        cout<<z<<" ";
    }
    cout<<n_l;
}
void solve(int j){
    cin>>n>>k;
    // if(j==64){
    //     cout<<"# "<<n<<" "<<k<<n_l;
    //     return;
    // }
    // if(n>5 || j>6){
    //     return;
    // }
    if(n<=10 && k>fac(n)){
        cout<<"No\n";
        return;
    }
    if(k==1){
        if(n==1){
            cout<<"Yes\n";
            cout<<"1\n";
            return;
        }
        cout<<"No\n";
        return;
    }
    if(n%2==0 && k%2!=0){
        cout<<"No\n";
        return;
    }
    
    ll s1=k*(n+1)/(1ll*2);
    set<pll>st;
    vector<int>v;
    vector<vector<int>>ansf;
    int ct=0;
    for(int i=1;i<=n;i++){
            v.pb(i);
    }
    if(k%2!=0){
    vector<int>tmp(n);
    for(int i=0;i<n;i++){
        int pos=i+(n-1)/2;
        if(pos<n){
        tmp[i+(n-1)/2]=i+1;
        }
        else{
        tmp[pos-n]=i+1;
        }
    }
    ansf.pb(v);
    ansf.pb(tmp);
    pll a1=make_pair(get_hash(v,base[0],modulo[0]),get_hash(v,base[1],modulo[1]));
    pll a2=make_pair(get_hash(tmp,base[0],modulo[0]),get_hash(tmp,base[1],modulo[1]));
    vector<int>tmp1(n);
    ll req=3*(n+1)/2;
    for(int i=0;i<n;i++){
        tmp1[i]=req-(i+1+tmp[i]);
    }
    ansf.pb(tmp1);
    pll a3=make_pair(get_hash(tmp1,base[0],modulo[0]),get_hash(tmp1,base[1],modulo[1]));
    st.insert(a1);st.insert(a2);st.insert(a3);ct+=3;
    
    }
         do{
            pll x={get_hash(v,base[0],modulo[0]),get_hash(v,base[1],modulo[1])};
            if(st.count(x)){
                continue;
            }
            else{
                vector<int>v2;
                for(int i=0;i<n;i++){
                    v2.pb(n+1-v[i]);
                }
                pll x1=make_pair(get_hash(v2,base[0],modulo[0]),get_hash(v2,base[1],modulo[1]));
             //   dbg(st);
                if(st.count(x1)){
                    continue;
                }
                else{
                    ansf.pb(v);ansf.pb(v2);
                    ct+=2;
                    st.insert(x1);st.insert(x);
                }
            }
        }while(next_permutation(all(v)) && ct<k);
        if(ansf.size()<k){
            cout<<"No\n";
            return;
        }
        cout<<"Yes\n";
        trav(vv,ansf){
            print(vv);
        }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  int t=1;
  cin>>t;
   generate_hs();
   int j=0;
  while(j<t){
    solve(j++);
  }
    
}