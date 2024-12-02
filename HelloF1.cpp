#include <iostream>
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
int n,q;
vector<int>a,b,v;
vector<ll>suf;
vector<ll>seg,lazy;
const ll inf=1ll*1e18;
void build(int node ,int s,int e){
    if(e<s){
        return;
    }
    if(s==e){
        seg[node]=suf[s];
        return;
    }
    int md=(s+e)>>1;
    build(2*node+1,s,md);
    build(2*node+2,md+1,e);
    seg[node]=max(seg[2*node+1],seg[2*node+2]);
}
void push(int node){
    seg[2*node+1]+=lazy[node];
    seg[2*node+2]+=lazy[node];
    lazy[2*node+1]+=lazy[node];
    lazy[2*node+2]+=lazy[node];
    lazy[node]=0;
}
void update(int node,int s,int e,int l,int r,int val){
    if(s>e){
        return;
    }
    if(r<s || l>e){
        return;
    }
    if(l<=s && r>=e){
        seg[node]+=val;
        lazy[node]+=val;
        return;
    }
    push(node);
    int md=(s+e)>>1;
    update(2*node+1,s,md,l,r,val);
    update(2*node+2,md+1,e,l,r,val);
    seg[node]=max(seg[2*node+1],seg[2*node+2]);
}
ll query(int node,int s,int e,int l,int r){
    if(e<s){
        return 0;
    }
     if(r<s || l>e){
        return 0;
    }
    if(l<=s && r>=e){
        return seg[node];
    }
    push(node);
    int md=(s+e)>>1;
    return max(query(2*node+1,s,md,l,r),query(2*node+2,md+1,e,l,r));
}
void solve(){
    cin>>n>>q;
    a.resize(n);
    b.resize(n);
    v.resize(n);
    suf.resize(n+1,0);
    seg.resize(4*n+5,0);
    lazy.resize(4*n+5,0);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=1ll*a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        v[i]=a[i]-b[i];
    }
    for(int i=n-1;i>=0;i--){
        suf[i]=1ll*v[i]+suf[i+1];
    }
    build(0,0,n-1);
    for(int i=1;i<n;i++){
        ll c;
        cin>>c;
    }
    debug(query(0,0,n-1,0,n-1));
  
    while(q--){
        int p,x,y;
        ll z;
        cin>>p>>x>>y>>z;
        p--;
        sum-=1ll*a[p];
        a[p]=x;
        b[p]=y;
        sum+=1ll*a[p];
    
        update(0,0,n-1,0,p,(a[p]-b[p])-v[p]);
          
        v[p]=a[p]-b[p];
        cout<<sum-max(0ll,query(0,0,n-1,0,n-1))<<"\n";

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
 // cin>>t;
  while(t--){
    solve();
  }
    
}