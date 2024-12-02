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
const ll inf=2e18;
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
  unordered_map<ll,vector<ll>>ump;
void solve(){
    int m;
    cin>>m;
    vector<ll>vv;
    vector<ll>a[m],c[m];
    vector<pair<ll,pll>>block(m);
    int n=0;
    ll lenM=0;
    ll mxi=0;
    ump.clear();
    vector<ll>totals(m,0);
    for(int i=0;i<m;i++){
        cin>>block[i].ff>>block[i].ss.ff>>block[i].ss.ss;
        lenM+=block[i].ss.ff;
        mxi+=block[i].ss.ss;
        a[i].resize(block[i].ff);
        for(int j=0;j<block[i].ff;j++){
            cin>>a[i][j];
            vv.pb(a[i][j]);
            ump[a[i][j]].pb(i);
        }
        c[i].resize(block[i].ff);
        for(int j=0;j<block[i].ff;j++){
            cin>>c[i][j];
            totals[i]+=c[i][j];
        }
    }
    sort(all(vv));
    vv.erase(unique(all(vv)),vv.end());
    ll ans=inf;
    while(ans>0ll){
        if(!ump.count(lenM)){
            if(lenM<=mxi){
                cout<<"0\n";
                return;
            }
            else{
                break;
            }
        }
        ll r1=0;
        ll sz=0;
        ll ans1=0;
       // debug(lenM);
        trav(z,ump[lenM]){
            int dis=lower_bound(all(a[z]),lenM)-a[z].begin();
            ll sz1=totals[z]-c[z][dis];
            r1+=block[z].ss.ss;
            if(sz1>=block[z].ss.ff){
            ll k1=min(block[z].ss.ss,sz1);
             sz+=k1;
           }
            else{
                sz+=block[z].ss.ff;
                ll k1=(block[z].ss.ff-sz1);
                ans1+=k1;       
            }
        }
        sz+=(mxi-r1);
        if(sz>=lenM){
            ans=min(ans,ans1);
        }
        else if(lenM>mxi){
            break;
        }
        else{
            ans=min(ans,ans1+lenM-sz);
        }
       // debug(ans1);
       // debug(ans);
        lenM++;
        
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