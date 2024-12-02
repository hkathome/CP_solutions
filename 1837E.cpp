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
const int N=(1<<19)+10;
int fact[N];
void fac(){
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(1ll*fact[i-1]*i)%mod;
    }
}
void solve(){
int k;
cin>>k;
int n=(1<<k);
vector<int>v(n+1);
for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    v[i]=x;
}
ll ans=1;
int prev=1;
for(int i=k;i>=1;i--){
    int curTeams=(1<<(i));
    int losingTeams=curTeams/2;
    int cur=losingTeams;
    int free=0;
    int slow=1;
    for(int j=1;j<=curTeams;j+=2,slow++){
        if(v[j]==-1 && v[j+1]==-1){
            free++;//can occupy both positions in these pairs
            v[slow]=-1;
        }
        else if(v[j]!=-1 && v[j+1]!=-1){
            if(!(min(v[j],v[j+1])<=losingTeams && max(v[j],v[j+1])>losingTeams)){
                ans=0;
                cout<<"0\n";
                return;
            }
            v[slow]=min(v[j],v[j+1]);
            cur--;
        }
        else{
            if(v[j+1]==-1){
                swap(v[j],v[j+1]);
            }
            if(v[j+1]>losingTeams){
                cur--;
                v[slow]=-1;
            }
            else{
                v[slow]=v[j+1];
            }
        }
    }
    ll ans1=1ll*fact[cur]*expo(2,free);
    ans1%=mod;
    ans*=ans1;
    ans%=mod;
    
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
  //cin>>t;
  fac();
  while(t--){
    solve();
  }
    
}