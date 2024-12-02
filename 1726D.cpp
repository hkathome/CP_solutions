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


//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 

int expo(int a,int b){
    if(b==0)return 1;
    ll z=expo(a,b/2);
    z*=z;
    z%=mod;
    if(b&1){
        z*=1ll*a;
        z%=mod;
    }
    return z;
}
vector<vector<pair<int,int>>>adj;
vector<vector<pair<int,int>>>adj1;
set<int>st;
set<pair<int,int>>edges;
bool dfs1(int p,int s){
    st.insert(s);
    bool f=false;
    for(auto &z:adj1[s]){
        if(z.fi!=p){
            if(st.count(z.fi)){
                return true;
            }
        f|=dfs1(s,z.fi);
        }
    }
    return f;
}
int ct;
bool cycle(int u){
    if(ct<3){
        return false;
    }
    st.clear();
    return dfs1(-1,u);

}
bool check(int u,int v,int edge_num){
    if(ct==3){
        return true;
    }
    if(u>v){
        swap(u,v);
    }
    if(edges.count({u,v})){
        return false;
    }
    
    adj1[u].push_back({v,edge_num});
    adj1[v].push_back({u,edge_num});
    ct++;
   
    if(cycle(u)){
        assert(adj1[u].size()>0);
        adj1[u].pop_back();
        assert(adj1[v].size()>0);
        adj1[v].pop_back();
        ct--;
        return false;
    }
    edges.insert({u,v});
    return true;
}
bool presentInSet(int u,int v){
    if(u>v){
        swap(u,v);
    }
    return(edges.count({u,v}));
}
vector<bool>vis;
void dfs(int p,int s,int edge_num){
    vis[s]=true;
    for(auto &z:adj[s]){
        if(z.fi!=p){
            if(vis[z.fi]){
                //a cycle found so add to blue if it doesn't form any cycle
                if(!check(s,z.fi,z.se) && !presentInSet(s,z.fi)){
                    if(p!=-1){
                    check(p,s,edge_num);
                    // debug2(p,s);
                    }
                }
                // debug2(s,z.fi);
            }
            else{
                dfs(s,z.fi,z.se);
            }
        }
    }
    
}
void solve(){
int n,m;
cin>>n>>m;
adj.clear();
adj.resize(n+1);
vis.clear();
vis.resize(n+1,false);
adj1.clear();
adj1.resize(n+1);
ct=0;
edges.clear();
for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back({v,i});
    adj[v].push_back({u,i});
}
if(m==n-1){
    for(int i=1;i<=m;i++){
        cout<<i%2;
    }
    cout<<"\n";
    return;
}
dfs(-1,1,0);
vector<int>mark(m+1,0);

for(int i=1;i<=n;i++){
    for(auto &z:adj1[i]){
        assert(z.se>=1 && z.se<=m);
        mark[z.se]=1;
    }
}
 debug(ct);
debug(mark);
if(ct!=(m-n+1)){
    for(int i=1;i<=n;i++){
        for(auto &z:adj1[i]){
            debug2(i,z.fi);
        }
    }
}
assert(ct<=(m-n+1));
for(int i=1;i<=m;i++){
    cout<<mark[i];
}
cout<<"\n";

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


