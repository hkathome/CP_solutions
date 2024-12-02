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
  vector<int>a,b;
  bool check_Isolated(vector<int>&next,vector<int>&prev,int i,int j){
    int j1=j;
    while(j<=i){
        if(next[j]==-1 && prev[j]==-1){
            return false;
        }
        else if(next[j]==-1 && prev[j]<j1){
            return false;
        }
        else if(prev[j]==-1 && next[j]>i){
            return false;
        }
        else if(next[j]>i && prev[j]<j1){
            return false;
        }
        j++;
    }
    for(int i1=i+1;i1<n;i1++){
          if(next[i1]==-1 && prev[i1]==-1){
            return false;
        }
        else if(next[i1]==-1 && prev[i1]<=i){
            return false;
        }
        else if(prev[i1]<=i){
            return false;
        }
    }
    return true;
  }
void solve(){
    int n;
    cin>>n;
    a.clear();a.resize(n);
    b.clear();b.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<n;j++){
        cin>>b[i];
    }
    vector<int>next(n+1,-1),prev(n+1,-1);
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            for(int j=i+1;j<n;j++){
                if(a[j]>b[i]){
                    break;
                }
                if(a[j]==b[i]){
                    next[i]=j;
                    break;
                }
            }
        }
        else{
            next[i]=i;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]!=b[i]){
            for(int j=i-1;j>=0;j--){
                if(a[j]>b[i]){
                    break;
                }
                if(a[j]==b[i]){
                    prev[i]=j;
                    break;
                }
            }
        }
        else{
            prev[i]=i;
        }
    }
    int l=-1;
    vector<bool>status(n,false);
    for(int i=0;i<n;i++){
        int j=l+1;
        bool f=check_Isolated(next,prev,i,j);
        status[i]=f;
        if(f){
            l=i;
        }
    }
    l=0;
    r=0;
    while(r<n){
        while(!status[r]){
            r++;
        }
        //left to right (l,r)
        int l1=l,r1=r;
        bool f=true;
        while(l1<=r1){
            if(prev[l1]==-1 && next[l1]==-1){
                cout<<"No\n";
                return;
            }
            else if(next[l1]==-1){
                f=false;
                break;
            }
        }
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
  cin>>t;
  while(t--){
    solve();
  }
    
}