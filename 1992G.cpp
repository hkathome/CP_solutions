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
const int mod=1e9+7;
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


//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
int fact[10005];
int ifact[10005];
void fac(){
    fact[0]=1;
    for(int i=1;i<10005;i++){
        fact[i]=(1ll*i*fact[i-1])%mod;
    }
    ifact[10004]=expo(fact[10004],mod-2);
    for(int i=10003;i>=0;i--){
        ifact[i]=(1ll*(i+1)*ifact[i+1])%mod;;
    }
}
int nCr(int n,int r){
    if(r>n)return 0;
    if(n==0 && r==0){
        return 1;
    }
    ll up=fact[n];
    ll d=(1ll*ifact[n-r]*ifact[r])%mod;
    up*=d;
    up%=mod; 
    return up;
}
void solve(){
    int n;
    cin>>n;
    ll ans=0;
    for(int x=1;x<=2*n+1;x++){
        for(int len=0;len<=min(n,x-1);len++){
            //count no. of subsets of size=len having Mex(S,len+1)=x;
            //conds:
            //S does not have len values<x which implies that x-1-len values<x present there and rest are greater
            //than x
            int lt=x-1-len;
            ll ans1=nCr(min(n,x-1),lt);
            int rt=len-lt;
            if(rt<0){
                continue;
            }
            
            ll ans2=1;
            if(rt>0){
                ans2=nCr(n-x,rt);
            }
            ll ansf=(((ans1*ans2)%mod)*1ll*x)%mod; 
            ans+=ansf;
            ans%=mod;
        }
    }
    cout<<ans<<'\n';
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
  while(t--){
    solve();
  }
    
}