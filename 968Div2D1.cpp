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
int Getmex(vector<int>&v){
    int l=0;
    int i=0;
    while(i<v.size()){
        if(v[i]==l){
            l++;
        }
        i++;
    }
    return l;
}
int Getmex(vector<int>&v,int x){
    int l=0;
    int i=0;
    while(i<v.size()){
        if(v[i]==l){
            l++;
             i++;
        }
        else if(l==x){
            l++;
        }
        else{
            i++;
        }
    }
    if(x==l){
        l++;
    }
    return l;
}
vector<int>papa;
int find(int x){
    if(papa[x]==x){
        return x;
    }
    return (papa[x]=find(papa[x]));
}
void solve(){
    int n,m;
    cin>>n>>m;
    int len=0;
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        int l;cin>>l;
        len+=l;
        for(int j=0;j<l;j++){
            int x;
            cin>>x;
            adj[i].pb(x);
        }
        sort(all(adj[i]));
    }
    vector<int>mex(n);
    int mxi=0;
    for(int i=0;i<n;i++){
        int mex1=Getmex(adj[i]);
        mex[i]=mex1;
        mxi=max(mxi,mex1);
    }
    vector<vector<int>>adjMex(mxi+1);
    vector<int>dp(len+1,0);
    for(int i=0;i<n;i++){
        adjMex[mex[i]].pb(i);
    }
  //  debug(mxi);
    int mm=0;
    for(int i=mxi;i>=0;i--){
        int ans=i;  
        trav(z,adjMex[i]){
            int mex1=Getmex(adj[z],i);
            if(mex1<=mxi){
                ans=max(ans,dp[mex1]);
            }
                ans=max(ans,mex1);
        }
        dp[i]=ans;
        if(adjMex[i].size()>1){
            mm=max(mm,dp[i]);
        }
        if(adjMex[i].size()==1){
            mm=max(mm,i);
        }
        
    }
  
    ll ans=0;
    for(int i=0;i<=min(m,len);i++){
        dp[i]=max({mm,dp[i],i});
        ll ans1=dp[i];
        ans+=ans1;
    }
     // debug(dp);
    //debug(ans);
    //mxi+1,mxi+2,mxi+3
    if(m>len){
        ans+=1ll*(m-len)*1ll*len;
        ll ans1=(1ll*(m-len)*(m-len+1));
        ans1/=(1ll*2);
     //  debug(ans1);
        ans+=ans1;
    }
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
  cin>>t;
  while(t--){
    solve();
  }
    
}