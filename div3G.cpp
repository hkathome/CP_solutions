#include <bits/stdc++.h>
#include <set>
#include <map>
#define ull unsigned long long 
#define lld long double
#define ll long long 
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
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

long long expo(long long a, long long b) {
	if(b==0){
        return 1;
    }
    ll z=expo(a,(b/(1ll*2)));
    z*=z;
    z%=mod;
    if(b&1){
        z*=a;
        z%=mod;
    }
    return z;
}

//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
vector<pair<int,pii>>edges;
vector<int>papa,comps;
ll ans;
int s;
int root(int x){
    if(papa[x]==x){
        return x;
    }
    return(papa[x]=root(papa[x]));
}
void unite(int x,int y,int w){
    x=root(x);
    y=root(y);
    if(x==y){
        return;
    }
    ll a=comps[x];
    ll b=comps[y];
  //  debug2(a,b);
    ll ct=a*b-1;
    ll ops=(s-w+1);
    ll ans1=expo(ops,ct);
  //  debug(ans1);
    ans*=ans1;
    ans%=mod;
    comps[x]+=comps[y];
    papa[y]=x;
}
void solve(){
    int n;
    cin>>n>>s;
    edges.clear();
    edges.resize(n-1);
    papa.clear(),comps.clear();
    papa.resize(n+1),comps.resize(n+1,1);
    for(int i=1;i<=n;i++){
        papa[i]=i;
        comps[i]=1;
    }
    for(int i=0;i<n-1;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edges[i]={w,{x,y}};
    }
    sort(edges.begin(),edges.end());
    int i=0;
    ans=1;
    while(i<edges.size()){
        int x,y,w;
        w=edges[i].fi,x=edges[i].se.fi,y=edges[i].se.se;
         unite(x,y,w);
    //     debug(x);
     //    debug(y);
     //    debug(w);
        i++;

    }
  
cout<<ans<<endl;

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