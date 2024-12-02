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


//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 

void solve(){
    int n;
    cin>>n;
    vector<ll>v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<ll>pre(n+2,0),suf(n+2,0);
    pre[1]=v[2]-v[1];
   
      vector<ll>prC(n+1,0),suC(n+2,0);
       prC[1]=1;
    for(int i=2;i<n;i++){
        if(abs(v[i+1]-v[i])>abs(v[i-1]-v[i])){
            pre[i]=pre[i-1];
            prC[i]=prC[i-1];
        }
        else{
            pre[i]=abs(v[i+1]-v[i])+pre[i-1];
             prC[i]=1+prC[i-1];
        }
    }
    pre[n]=pre[n-1];
    suf[n]=v[n]-v[n-1];
    prC[n]=prC[n-1];
    suC[n]=1;
    suC[n+1]=0;
    suf[n+1]=0;
    for(int i=n-1;i>=2;i--){
         if(abs(v[i+1]-v[i])>abs(v[i-1]-v[i])){
            suf[i]=abs(v[i-1]-v[i])+suf[i+1];
            suC[i]=1+suC[i+1];
        }
        else{
           suf[i]=suf[i+1];
            suC[i]=suC[i+1];
        }
    }
    // debug(pre);
    // debug(prC);
    suf[1]=suf[2];
    suC[1]=suC[2];
    // debug(suf);
    // debug(suC);
    int m;
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        ll ans=0;
        if(x<y){
            ans=(v[y]-v[x])-(pre[y-1]-pre[x-1])+(prC[y-1]-prC[x-1]);
        }
        else{
            ans=v[x]-v[y]-(suf[y+1]-suf[x+1])+suC[y+1]-suC[x+1];
        }
        cout<<ans<<"\n";

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
  while(t--){
    solve();
  }
    
}