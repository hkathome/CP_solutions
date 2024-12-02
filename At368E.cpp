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
vector<vector<int>>graph;
vector<vector<pii>>adj,adj1;
vector<int>dp;
vector<pii>A,B,S,T;
int n,m;
void init(){
dp.clear();graph.clear();adj.clear();adj1.clear();A.clear();B.clear();S.clear();T.clear();
dp.resize(m,0);
A.resize(m);B.resize(m);S.resize(m);T.resize(m);
adj.resize(n+1);
adj1.resize(n+1);
}
void solve(){
    
    cin>>n>>m;
    init();
    cin>>dp[0];
    queue<int>q;
 
    graph.resize(m+1);
    vector<int>T2(m+1);
    for(int i=0;i<m;i++){
        int a,b,s,t;
        cin>>a>>b>>s>>t;
        A[i]={a,s};
        B[i]={b,t};
        S[i]={s,i};
        T[i]={t,i};
        adj[a].pb({s,i});
        adj1[b].pb({t,i});
        T2[i]=t;
    }
    //debug(T);
    //debug("here");
    for(int i=1;i<=n;i++){
        sort(all(adj[i]));
        sort(all(adj1[i]));
    }
    sort(all(T));
    int root=-1;
    vector<int>in(m+1,0);
    for(int i=0;i<m;i++){
        int idx=T[i].ss;
        int b=B[idx].ff;
        auto it=lower_bound(all(adj[b]),make_pair(T[i].ff,-1));
        while(it!=adj[b].end()){
            graph[idx].pb(it->ss);
            in[it->ss]++;
            it++;
        } 
    }
    //debug("here1");
    vector<bool>vis(m+1,false);
    for(int i=0;i<m;i++){
        if(in[i]==0){
            q.push(i);
            vis[i]=true;
        }
    }
    //debug(in);
    //debug(vis);
    //debug("here2");
    while(!q.empty()){
        int s=q.front();q.pop();
        //debug2(s,dp[s]);
        trav(z,graph[s]){
            //debug(z);
            if(S[z].ff+dp[z]<T2[s]+dp[s]){
                dp[z]=T2[s]+dp[s]-S[z].ff;
                //debug2(z,dp[z]);
            }
            in[z]--;
            if(in[z]==0 && !vis[z]){
                vis[z]=true;
                q.push(z);
            }
        }
    }
    for(int i=1;i<m;i++){
        cout<<dp[i]<<" ";
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