#include <bits/stdc++.h>
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
int expo(ll a,ll b,int MOD=mod){
    a%=MOD;
    if(b==0){
        return 1;
    }
    ll z=expo(a,b/(1ll*2),MOD);
    z*=z;
    z%=MOD;
    if(b&1ll){
        z*=a;
        z%=MOD;
    }
    return z;
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
    int n,m;
    cin>>n>>m;
    vector<ll>a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<m;j++){
        cin>>b[j];
    }
    vector<int>vv(n);
    iota(all(vv),0);
    sort(all(vv),[&a](int i,int j){
        return a[i]>a[j];
    });
    //sorting programmers in decreasing order of their capacity

    vector<vector<int>>suf(m+1,vector<int>(n+2,n+1));
    for(int i=0;i<m;i++){
        int r=0;
        for(int j=0;j<n;j++){
            r=min(n,max(r,j));
            while(r<n && a[vv[r]]*1ll*(r-j+1)<b[i]){
                r++;
            }
            suf[i][j]=r;
        }
    }
    // debug(vv);
    // debug(suf);
    vector<int>dp(1<<m,n);
    vector<int>papa(1<<m,-1);
    dp[0]=-1;
    for(int mask=0;mask<(1<<m);mask++){
        for(int j=0;j<m;j++){
            if(!(mask&(1<<j)) &&  dp[mask|(1<<j)] >suf[j][dp[mask]+1]){
                dp[mask|(1<<j)]=suf[j][dp[mask]+1];
                papa[mask|(1<<j)]=mask;
            }
        }
    }
    int mask=(1<<m)-1;
    // debug(dp[mask]);
    if(dp[mask]>(n-1)){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    vector<vector<int>>ans(m);
    while(mask>0){
        int bj=mask^papa[mask];
        int idx=__builtin_ctz(bj);
        for(int j=dp[papa[mask]]+1;j<=dp[mask];j++){
            ans[idx].pb(vv[j]);
        }
        mask=papa[mask];

    }
    for(int i=0;i<m;i++){
        cout<<ans[i].size()<<" ";
        trav(z,ans[i]){
            cout<<z+1<<" ";
        }
        cout<<"\n";
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
  //cin>>t;
  while(t--){
    solve();
  }
    
}