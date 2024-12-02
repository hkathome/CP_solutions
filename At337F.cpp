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

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>v(n+1);
    vector<vector<int>>adj(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        adj[v[i]].pb(i);
    }
    vector<int>color(n+1,0);
    int ans=0;
    int r=0;
    int ct=0;
    while((r+1)<=n){
        if(color[v[r+1]]%k>0){
            color[v[r+1]]++;
            r++;
            continue;
        }
        else{
            //k+1 is same as 1st as both need a new box
            if(ct<m){
                ct++;
                color[v[r+1]]++;
                r++;
            }
            else{
                break;
            }

        }

    }
    // debug(r);
    vector<int>contri(n+1,0);
    vector<bool>mark(n+1,false);
    for(int i=1;i<=r;i++){
        if(!mark[v[i]]){
        int boxes=(color[v[i]]+k-1)/k;
        int ans1=min(boxes*k,(int)adj[v[i]].size());
        contri[v[i]]=ans1;
        ans+=ans1;
        mark[v[i]]=true;
        }
    }
    // debug(r);
    cout<<ans<<"\n";
    // debug(contri);
    for(int i=2;i<=n;i++){
        //i is the front element
        color[v[i-1]]--;
        v.pb(v[i-1]);
        if(color[v[i-1]]%k>0){
            // debug2(i,ans);
            cout<<ans<<"\n";
            continue;
        }
        else{
            // debug(i);
            // debug(contri);
            // debug(color);
            ct--;
            int boxes=(color[v[i-1]]+k-1)/k;
            ans-=contri[v[i-1]];
            //  if(i==6){
            //     debug(v[i-1]);
            //     debug(contri[v[i-1]]);
            //  }
            int ans1=min(boxes*k,(int)adj[v[i-1]].size());
             contri[v[i-1]]=ans1;
             
            //  if(i==6){
            //     debug(v[i-1]);
            //     debug(contri[v[i-1]]);
            //  }
            ans+=contri[v[i-1]];
            int newAdded=-1;
            while((r+1)<(int)v.size()){
                if(color[v[r+1]]%k>0){
                color[v[r+1]]++;
                r++;
                continue;
                }
                else{
                  //k+1 is same as 1st as both need a new box
                    if(ct<m){
                      ct++;
                      color[v[r+1]]++;
                      r++;
                      newAdded=r;
                      break;
                     }
                     else{
                      break;
                    }
                }
            }
            // debug2(i,r);
            // debug(contri);
            // debug(color);
            
            // debug(ans);
            ans-=contri[v[r]];
             boxes=(color[v[r]]+k-1)/k;
            ans1=min(boxes*k,(int)adj[v[r]].size());
            contri[v[r]]=ans1;
            ans+=ans1;
        }
        // debug(v);
        cout<<ans<<"\n";

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