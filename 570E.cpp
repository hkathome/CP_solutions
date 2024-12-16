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
#include <cstring>
using namespace std;
const int mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
const int N=100;
const int M=100;
const int inf=1e8;
//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
int n,m,req;
vector<vector<char>>mat;
vector<vector<ll>>dp[2];
// int f(int i1,int i2,int len){
//     if(i1>=n || i2<0){
//         return 0;
//     }
//     if(dp[i1][i2][len]!=-1){
//         return dp[i1][i2][len];
//     }
//     int j1=len-i1+0;
//     int j2=m-1-(len-(n-1-i2));
//     if(i1==i2 && j1==j2){
//         return (dp[i1][i2][len]=1);
//     }
//     if(mat[i1][j1]!=mat[i2][j2]){
//         return (dp[i1][i2][len]=0);
//     }
//      if(len==req){
//         pii p1={i1+1,j1};
//         pii p2={i1,j1+1};
//         dp[i1][i2][len]=0;
//         if(p1==make_pair(i2,j2) || p2==make_pair(i2,j2)){
//             dp[i1][i2][len]=1;
//         }
//         return dp[i1][i2][len];
//     }
   
//     ll ans=f(i1,i2,len+1)+f(i1+1,i2,len+1)+f(i1,i2-1,len+1)+f(i1+1,i2-1,len+1);
//     ans%=mod;
//     return (dp[i1][i2][len]=ans);
// }
bool check(int i1,int j1,int i2,int j2){
    if(i1<0 || i1>=n || i2<0 || i2>=n
    || j1<0 || j1>=m || j2<0 || j2>=m){
        return false;
    }
    pii p1={i1+1,j1};
    pii p2={i1,j1+1};
    if((p1==make_pair(i2,j2) || p2==make_pair(i2,j2)) && mat[i1][j1]==mat[i2][j2] ){
            return true;
    }
    return false;

}
bool ok(int i1,int j1,int i2,int j2){
     if(i1<0 || i1>=n || i2<0 || i2>=n
    || j1<0 || j1>=m || j2<0 || j2>=m){
        return false;
    }
    return true;
}
void solve(){
    cin>>n>>m;
    mat.resize(n);
    dp[0].resize(n+1,vector<ll>(n+1,0ll));
    dp[1]=dp[0];
    for(int i=0;i<n;i++){
        mat[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
//  dbg(dp);
   req=(n+m-2)/2;
    if((n+m)%2==0){
        for(int i1=0;i1<=min(n-1,req);i1++){
            int j1=req-i1+0;
            if(j1>=0 && j1<m){
               // dbgm(i1,j1);
             //   assert(i1+req==n-1 && j1+req==m-1);
                
                dp[0][i1][i1]=1;
            }
        }
    }
    else{
    for(int i1=0;i1<=min(n-1,req);i1++){
        for(int i2=n-1;i2>=n-1-req;i2--){
            if(i1>i2){
                continue;
            }
            int j1=req-i1+0;
            int j2=m-1-(req-(n-1-i2));
            if(check(i1,j1,i2,j2)){
             //   dbgm(i1,j1,i2,j2);
                dp[0][i1][i2]=1;
            }
        }
    }
    }
    //dbg(dp);
    for(int len=req-1;len>=0;len--){
    for(int i1=n-1;i1>=0;i1--){
        for(int i2=0;i2<n;i2++){
                int j1=len-i1+0;
                int j2=m-1-(len-(n-1-i2));
                if(!ok(i1,j1,i2,j2)){
                    continue;
                }
                if(mat[i1][j1]==mat[i2][j2]){
                    ll ans=dp[0][i1][i2]+dp[0][i1+1][i2]+(i2>0?dp[0][i1][i2-1]:0ll)+(i2>0?dp[0][i1+1][i2-1]:0ll);
                    ans%=mod;
                    dp[1][i1][i2]=ans;
                    dp[1][i1][i2]%=mod;
                }
            }
            
            
        }
        dp[0]=dp[1];
        dp[1].clear();
        dp[1].resize(n+1,vector<ll>(n+1,0ll));
    }
    cout<<dp[0][0][n-1];




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
  //cin>>t;
  while(t--){
    solve();
  }
    
}