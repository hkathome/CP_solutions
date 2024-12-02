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

const ll inf=1e18+10;
//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 

void solve(){
int n;
cin>>n;
vector<int>v(n);
vector<ll>pre(n+1);
ll sum=0;
for(int i=0;i<n;i++){
    cin>>v[i];
    sum+=v[i];
    pre[i]=sum;
}
vector<ll>suf(n+1,inf);
for(int i=n-1;i>=0;i--){
    suf[i]=min(suf[i+1],pre[i]);
}
ll k=0;
sum=0;
for(int i=0;i<n-1;i++){
    //is sum+v[i] better k than k(earlier)
    if(sum+v[i]>k){
        sum+=v[i];
    }
    else{
        sum=k;
    }
    if(sum<=pre[i]){
        //only it can be == case
        k=pre[i];
        sum=pre[i];
    }
    else{
        //sum>pre[i]
        ll dif=suf[i+1]-pre[i];
        if(dif>=0){
            continue;
        }
        dif*=-1ll;
        ll sum1=sum-dif;
        sum1=max(sum1,k);
        if(sum1<pre[i]){
            k=pre[i];
            sum=pre[i];
        }
    }
}
cout<<k<<endl;

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