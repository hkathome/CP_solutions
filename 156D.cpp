#include <bits/stdc++.h>
#include <set>
#include <unordered_set>
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
template <typename T> void chkmn(T &a, const T &b) { a = min(a, b); }
template <typename T> void chkmx(T &a, const T &b) { a = max(a, b); }
 

//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
int expo(ll a,ll b,int MOD=mod){
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
const int N=5e5;
ll fact[N];
void fac(){
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(1ll*i*fact[i-1])%mod;
    }
}
int fwk[N];
int n;
void update(ll &ans,int x){
    ans*=1ll*x;
    ans%=mod;
}
int query(int idx){
    idx++;
    int sum=0;
    while(idx>0){
        sum+=fwk[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}

void solve(){
    int q;
    cin>>n>>q;
    string s;
    cin>>s;
    ll ans=1;
    //need a way to calculate total ? and the number of ? between first < and >
    set<int>stL,stG;//L-> < , G-> >
    for(int i=0;i<n-1;i++){
        if(s[i]=='<'){
            stL.insert(i);
        }
        else if(s[i]=='>'){
            stG.insert(i);
        }
        else{
            if(i>0){
            update(ans,i);
            }
        }
    }
 
  bool f=false;
   
    if(s[0]=='?'){
        f=true;
    }
    
    cout<<(f?0:ans)<<"\n";
    while(q--){
        int pos;
        char w;
        cin>>pos>>w;
        pos--;
        if(s[pos]==w){
        }
        else{
            if(s[pos]=='?' && pos>0){
                update(ans,expo(pos,mod-2));
             }

            s[pos]=w;
            
            if(w=='?' && pos>0){
               update(ans,pos);
            }
        }

        if(s[0]=='?'){
             f=true;
         }
         else{
            f=false;
         }
         debug(ans);
          cout<<(f?0:ans)<<"\n";

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
  fac();
  //cin>>t;
  while(t--){
    solve();
  }
    
}
