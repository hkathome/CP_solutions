#include <bits/stdc++.h>
#include <set>
#include <map>
#define ull unsigned long long 
#define lld long double
#define ll long long 
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
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



//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
const int N=655;
void solve(){
int n;
cin>>n;
vector<vector<int>>Mp(N,vector<int>(n+1,0));
for(int i=1;i<N;i++){
    Mp[i].resize(n+1,0);
}
vector<vector<int>>vv(n+1);
vector<int>a(n+1),b(n+1);
for(int i=1;i<=n;i++){
    cin>>a[i];
}

for(int j=1;j<=n;j++){
    cin>>b[j];
    vv[a[j]].pb(b[j]);
    if(a[j]<N){
        Mp[a[j]][b[j]]++;
    }
}
ll ans=0;
for(int i=2;i<=n;i++){
    if(vv[i].empty())continue;
    //j=i to be handled later
    ll ans1=0;
    vector<int>v;
    for(int j=1;j<=i && i*j<=2*n;j++){
        int aj=j;
        if(vv[aj].empty())continue;
        v.pb(j);
    }
    for(auto &z:vv[i]){
        for(auto &z1:v){
            int req=z1*i-z;
            int aj=z1;
                if(req<=n && req>=1){
                if(aj!=i){
                 ans+=1ll*Mp[z1][req];
                }
                else if(req!=z){
                    ans1+=1ll*Mp[z1][req];
                }
                }
        

        }
    }
    ans+=(ans1/(1ll*2));
}
//ai==aj && bi==bj  means (a,a), (a,a) pairs i.e number of same pairs
// debug(ans);
map<pair<int,int>,int>Mp2;
for(int i=1;i<=n;i++){
    // debug2(a[i],b[i]);
    if(1ll*a[i]*a[i]==1ll*2*b[i]){
        // debug(a[i]);
        if(Mp2.count(make_pair(a[i],b[i]))){
        Mp2[make_pair(a[i],b[i])]++;
        }
        else{
             Mp2[make_pair(a[i],b[i])]=1;
        }
    }
}
// debug(Mp2);
for(auto &z:Mp2){
    ans+=((1ll*z.ss*(z.ss-1))/(1ll*2));
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