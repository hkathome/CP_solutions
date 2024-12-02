#include <bits/stdc++.h>
#include <set>
#include <map>
#include <queue>
#define ull unsigned long long 
#define lld long double
#define ll long long 
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define trav(z,vv) for(auto &z:vv)
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
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

vector<int>papa;
vector<int>cts;
int root(int x){
    if(papa[x]==x){
        return x;
    }
    return papa[x]=root(papa[x]);
}
bool unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y){
        return false;
    }
    papa[y]=x;
   cts[x]+=(cts[y]+1);
   return true;
}

void solve(){
int n,m;
cin>>n>>m;
vector<vector<pii>>adj(n+1);
papa.clear();
papa.resize(n+1);
cts.clear();
cts.resize(n+1,0);
for(int i=1;i<=n;i++){
    papa[i]=i;
    cts[i]=0;
}
vector<pii>edges(m);
vector<char>color(m);
for(int i=0;i<m;i++){
    int u,v;
    char w;
    cin>>u>>v>>w;
    adj[u].pb({v,i});
    adj[v].pb({u,i});
    edges[i]={u,v};
    color[i]=w;

}
string s;
cin>>s;
vector<int>anss;
vector<int>reds,blues;
vector<bool>mark(n+1,false);
for(int i=0;i<m;i++){
    int l=edges[i].fi-1;
    int r=edges[i].se-1;
    if(s[l]==s[r] && s[l]==color[i]){
        if(color[i]=='R'){
            reds.pb(i);
        }
        else{
            blues.pb(i);
        }
    }
 
}
for(auto &z:reds){
    int l=edges[z].fi;
    int r=edges[z].se;
    if(unite(l,r)){
        mark[l]=mark[r]=true;
        anss.pb(z);
    }
}
for(auto &z:blues){
    int l=edges[z].fi;
    int r=edges[z].se;
    if(unite(l,r)){
        mark[l]=mark[r]=true;
        anss.pb(z);
    }
}
queue<int>q;
for(int i=1;i<=n;i++){
    if(mark[i]){
        q.push(i);
    }
}
while(!q.empty()){
    int x=q.front();
    q.pop();
    trav(z,adj[x]){
        if(!mark[z.fi] && color[z.se]==s[z.fi-1]){
            if(unite(x,z.fi)){
            q.push(z.fi);
            mark[z.fi]=true;
            anss.pb(z.se);
            }
        }
    }
}
int ct=0;
for(int i=1;i<=n;i++){
    ct+=mark[i];
}
if(ct!=n){
    cout<<"No\n";
    return;
}
for(int i=0;i<m;i++){
    int u=edges[i].fi;
    int v=edges[i].se;
    if(unite(u,v)){
        anss.pb(i);
    }
}
cout<<"Yes\n";
trav(z,anss){
    cout<<z+1<<" ";
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
  //cin>>t;
  while(t--){
    solve();
  }
    
}