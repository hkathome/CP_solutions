#include <iostream>
#include <algorithm>
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

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
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
const int N=3e5+10;
ll fact[N];
void fac(){
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=1ll*i*fact[i-1];
        fact[i]%=mod;
    }
}
//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
ll nCr(int n,int r){
    if(r==0){
        return 1;
    }
    if(r>n || r<0 || n<0)return 0;
    ll up=fact[n];
    ll d=expo(fact[n-r],mod-2)*expo(fact[r],mod-2);
    d%=mod;
    up*=d;
    up%=mod;
    return up;
}
vector<vector<int>>adj;

ll ans=0;
vector<ll>dp;
void dfs(int p,int s){
    dp[s]=1;
    trav(z,adj[s]){
        if(z!=p){
            dfs(s,z);
            dp[s]*=(dp[z]+1);
            dp[s]%=mod;
        }
    }
}
void calc(int p,int s){
    if(p!=-1){
        ll ans1=dp[p];
        ans1*=expo((dp[s]+1)%mod,mod-2);
        ans1%=mod;
        dp[s]*=(ans1+1);
        dp[s]%=mod;
    }
    trav(z,adj[s]){
        if(z!=p){
            calc(s,z);
        }
    }

}
void solve(int id){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1);
    adj.clear();
    adj.resize(n+1);
    vector<pii>edges(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        edges[i].ff=u;
        edges[i].ss=v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

ans=0;
dfs(-1,1);
//debug(dp);
//calc(-1,1);
//debug(dp);
for(int i=1;i<=n;i++){
    ans+=dp[i];
    ans%=mod;
}
ans++;
ans%=mod;
cout<<ans<<"\n";

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
    fac();
  int t=1;
  cin>>t;
  int id=0;
  while(id<t){
    solve(id++);
  }
    
}