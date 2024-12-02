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
const int N=200005;
ll fact[N];
void fac(){
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=1ll*i*fact[i-1];
        fact[i]%=mod;
    }
}
ll nCr(int n,int r){
    ll l=fact[n];
    ll d=(1ll*expo(fact[r],mod-2)*expo(fact[n-r],mod-2))%mod;  
    l*=d;
    l%=mod;
    return l;
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    //E(X[i])=Expected value for ith pair of friends
    //E[Sum(X)]=E[X[0]]+E[X[1]]+...+E[X[m]] =m*E[X[0]] as all pairs are equally probable
    ll sum=0;
    for(int i=0;i<m;i++){
        int x,y,s;
        cin>>x>>y>>s;
        sum+=1ll*s;
    }
    sum%=mod;
    ll total=1ll*n*(n-1);total/=(1ll*2);
    total%=mod;
    ll inv=expo(total,mod-2);
    ll ans1=(1ll*k*sum)%mod;
    ans1*=inv;ans1%=mod;
      if(n==2){
        if(m==0){
            cout<<"0\n";
        }
        else{
            ll ansf=1ll*k*(k-1);
            ansf/=(1ll*2);
            ansf%=mod;
            cout<<(ans1+ansf)%mod<<"\n";
        }
        return;
    }
   // debug(ans1);
   ll ans=0;
   ll val=1;
   ll val2=(total-1)*inv;
   val2%=mod;
   val2=expo(val2,k);
    ll inv2=total%mod*expo(total-1,mod-2);inv2%=mod;
    for(int x=0;x<=k;x++){
        ll ans2=nCr(k,x)*val;
        ans2%=mod;ans2*=val2;ans2%=mod;
        val*=inv;val%=mod;
        val2*=inv2;
        val2%=mod;
        if(x>1){
            ll x2=1ll*x*(x-1);
            x2/=(1ll*2);
            x2%=mod;
            ans2*=x2;
            ans2%=mod;
            ans+=ans2;
            ans%=mod;
        }
    }
    ans*=1ll*m;
    ans%=mod;
   // debug(ans);
    //debug(ans1);
    ans+=ans1;
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
  int t=1;
  fac();
  cin>>t;
  while(t--){
    solve();
  }
    
}