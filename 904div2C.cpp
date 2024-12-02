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
const int inf=1e9+10;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pii>vv(n);
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>vv[i].ff>>vv[i].ss;
        v.pb(vv[i].ff);
        v.pb(vv[i].ss);
    }
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    int k=v.size();
    vector<int>pre(k+1,0);
    for(int i=0;i<n;i++){
        int dis=lower_bound(all(v),vv[i].ff)-v.begin();
        pre[dis]++;
        dis=lower_bound(all(v),vv[i].ss)-v.begin();
        pre[dis+1]--;
    }
    //debug(v);
    int mx=0;
    for(int i=0;i<k;i++){
        if(i>0)
        pre[i]+=pre[i-1];

        mx=max(mx,pre[i]);
    }
      //debug(pre);
        //debug(mx);
  
    sort(all(vv));
    int l1=1;
    for(int i=0;i<n;i++){
        if(l1>=vv[i].ff){
            l1=max(l1,vv[i].ss);
        }
        else{
            cout<<mx<<endl;
            return;
        }
    }
    if(l1<m){
          cout<<mx<<endl;
            return;
    }
    vector<int>fst(k,n+1),lst(k,-1);
    vector<int>ones,lasts;
    int idx=0;
    for(int i=0;i<n;i++){
        int l=vv[i].ff;
        if(l==1){
            ones.pb(vv[i].ss);
        }
        if(vv[i].ss==m){
            lasts.pb(vv[i].ff);
        }
        while(idx<k && v[idx]>=l && v[idx]<=vv[i].ss){
            fst[idx]=l;
            idx++;
        }
        swap(vv[i].ff,vv[i].ss);
    }
    sort(all(ones));
    sort(all(lasts));
    sort(all(vv),greater<pii>());
    idx=k-1;
    for(int i=0;i<n;i++){
        int r=vv[i].ff;
        while(idx>=0 && r>=v[idx] && v[idx]>=vv[i].ss){
            lst[idx]=r;
            idx--;
        }
    }
 
    //debug((int)ones.size());
    int ans=0;
    for(int i=0;i<k;i++){
        int mxi=pre[i];
        int minil=inf;
        int l=fst[i];
        if(l>1){
            minil=0;
        }
        else{
            int dis1=lower_bound(all(ones),v[i])-ones.begin();
           // debug(dis1);
            //dis1 segments end before v[i] so we don't take them
            minil=(int)ones.size()-dis1;
        
        }
        int minir=inf;
        int r=lst[i];
       
        if(r<m){
            minir=0;
        }
        else{
            int dis1=upper_bound(all(lasts),v[i])-lasts.begin();
            //dis1 segments end ahead of v[i], so we don't take them
            minir=dis1;
            
        }
        // debug2(l,r);
        // debug2(i,mxi);
        // debug2(minil,minir);
        ans=max(ans,mxi-min(minil,minir));
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