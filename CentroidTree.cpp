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
template <class T,class V>
class CentroidTree{
    vector<V> dp,heavyChild;
    vector<bool>marked;
    int m;
    int sz;
    public:
    vector<vector<T>>centroid;//adjacency list to hold centroid tree
    CentroidTree(int n, vector<vector<int>>&adj){
        this->m=n;
        this->centroid.resize(m+1);
        this->dp.resize(m+1);
        this->marked.resize(m+1,false);
        this->heavyChild.resize(m+1,-1);
        this->DecomposeTree(adj,-1,-1,1);

    }
    bool isCentroid(int s){
        if(marked[s])return true;
        if(sz>=2*dp[s]){
            return true;
        }
        return false;
    }
    int computeCentroid(vector<vector<T>>&adj,int p, int s){
        int ct=1;
        int mxi=0;
        trav(z,adj[s]){
            if(marked[z] || z==p){
                continue;
            }
           
            int ct1=computeCentroid(adj,s,z);
            if(ct1>mxi){
                heavyChild[s]=z;
                mxi=ct1;
            }
            
            ct+=ct1;
        }
        dp[s]=mxi;
        if(p==-1){
            sz=ct;
        }
        return ct;
    }
    void DecomposeTree(vector<vector<T>>&adj,int prev,int p,int s){
       // debug(s);
        if(p==-1){// a new subtree
            computeCentroid(adj,-1,s);
        }
        if(isCentroid(s)){
            marked[s]=true;
             debug2(prev,s);
            if(prev!=-1){
               
            centroid[prev].pb(s);
            centroid[s].pb(prev);
            }
            trav(z,adj[s]){
                if(!marked[z]){
                    DecomposeTree(adj,s,-1,z);
                }
            }
        }
        else{   
               DecomposeTree(adj,prev,s,heavyChild[s]);
        }
    }

    
};
void solve(){
int n;
cin>>n;
vector<vector<int>>adj(n+1);
for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;adj[u].pb(v);adj[v].pb(u);
}
debug(adj);
CentroidTree<int,int> centroidTree(n,adj);
debug(centroidTree.centroid);

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