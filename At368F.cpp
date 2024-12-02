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
class Grundy{
    int n;
    vector<ll>g;
    vector<vector<int>>adj;
    public:
    Grundy(int n1){
        this->n=n1;
        this->g.clear();
        this->g.resize(n+1);
        this->adj.clear();
        this->adj.resize(n+1);
        debug(n);
        for(int i=n;i>=1;i--){
        createGraph(i);
        }
    }
    void createGraph(int s){
        //function to create a DAG recursively
        if(adj[s].size()>0){
            return;
        }
        if(s==1){
            g[s]=0;
            return;
        }
        set<ll>st;
        for(int i=1;i<s;i++){
            if(s%i==0){
                //debug2(s,i);
                adj[s].pb(i);
                createGraph(i);
                st.insert(g[i]);
            }
        }
        if(s==1){
            g[1]=0;
        }
        else{
            int gg=0;
            while(!st.empty()){
                if(gg==*st.begin()){
                    st.erase(st.begin());
                    gg++;
                }
                else{
                    break;
                }
            }
            g[s]=gg;
        }
    }

    void printGrundy(){
        for(int i=1;i<=n;i++){
            debug2(i,g[i]);
        }
    }

};
const int N=1e5+10;
int prime[N];
void sieve(){
    for(int i=2;i*i<N;i++){
        if(!prime[i]){
            for(int j=i*i;j<N;j+=i){
                if(!prime[j]){
                    prime[j]=i;
                }
            }
        }
    }
    for(int i=1;i<N;i++){
        if(!prime[i]){
            prime[i]=i;
        }
    }
}
void solve(){
   int n;
   cin>>n;
   int ans=0;
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    int g=0;
    while(x>1){
        int y=prime[x];
        while(x%y==0){
            x/=y;
            g++;
        }
    }
    ans^=g;
   }
   cout<<(ans==0?"Bruno":"Anna")<<"\n";
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
  sieve();
  //cin>>t;
  while(t--){
    solve();
  }
    
}