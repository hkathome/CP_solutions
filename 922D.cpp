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

ll inf=1e15;

int n;
vector<ll>v,seg,dp1,dp2,pre;


void update(int node, int s, int e, int pos,ll val) {
    if (e < s) {
        return;
    }
    if (s==e) {
        seg[node] += val;
        return;
    }
    int md = s + (e - s) / 2;
    if(pos<=md){
    update(2 * node + 1, s, md, pos, val);
    }
    else{
    update(2 * node + 2, md + 1, e, pos, val);
    }
    seg[node] = min(seg[2 * node + 1], seg[2 * node + 2]);
}
ll query(int node, int s, int e, int l, int r) {
    if (e < s) {
        return inf;
    }
    if (e < l || s > r) {
        return inf;
    }
    if (l <= s && e <= r) {
        return seg[node];
    }
    int mid = s + (e - s) / 2;
    ll ans = min(query(2 * node + 1, s, mid, l, r), query(2 * node + 2, mid + 1, e, l, r));
   
    return ans;
}
bool ok(ll val){
    ll sum=0;
    ll sum2=0;
    ll mxi=0;
    dp1.clear();
    dp1.resize(n+1,inf);
    dp2=dp1;
    seg.clear();
    seg.resize(4*n+100);
    dp2[0]=0;
    dp1[0]=0;
    vector<pii>vv(n+1);
    update(0,0,n,0,0);
    for(int i=0;i<n;i++){
        if(v[i]>val){
            return false;
        }
        //including i
        int pos1=lower_bound(all(pre),pre[i+1]-val)-pre.begin();
       // debug(pre[i+1]-val);
        // debug2(i,pos1);
        vv[i+1].ff=pos1;
        int pos2=lower_bound(all(pre),pre[i]-val)-pre.begin();
        vv[i+1].ss=pos2;
    }
    // debug(vv);
    for(int i=0;i<n;i++){
        dp2[i+1]=query(0,0,n,vv[i+1].ss,i)+1ll*v[i];
        // if(i==3){
        //     debug2(vv[i+1].ss,i);
        // }
        update(0,0,n,i+1,dp2[i+1]);
        // debug2(i+1,dp2[i+1]);
        dp1[i+1]=query(0,0,n,vv[i+1].ff,i);
        // debug2(dp1[i+1],dp2[i+1]);
          dp1[i+1]=min(dp1[i+1],dp2[i+1]);
        
    }
    
    // debug(sum);
    // debug(mxi);

    // debug(sum2);
    return dp1[n]<=val;
}
void solve(){
    cin>>n;
    v.clear();
    v.resize(n);
    pre.clear();
    pre.resize(n+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
        pre[i+1]=v[i];
    }
    for(int i=1;i<=n;i++){
        pre[i]+=pre[i-1];
    }
    // debug(pre);
    ll l=0;
    ll r=inf;
    // debug(ok(5));
    while(l<=r){
        ll md=l+(r-l)/(1ll*2);
        if(ok(md)){
            r=md-1;
        }
        else{
            l=md+1;
        }
    }
    cout<<r+1<<"\n";
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