#include <bits/stdc++.h>
#include <set>
#include <map>
#define ull unsigned long long 
#define lld long double
#define ll long long 
#define pb push_back
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
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

void solve(){
int n;
cin>>n;
vector<int>v(n+1);
vector<int>mins;
for(int i=1;i<=n;i++){
    cin>>v[i];
    mins.pb(v[i]);
}
sort(mins.begin(),mins.end());
mins.erase(unique(all(mins)),mins.end());
int k;
cin>>k;
int m=mins.size();
vector<int>disMin(m,-1);
for(int i=1;i<=n;i++){
    int idx=lower_bound(all(mins),v[i])-mins.begin();
    disMin[idx]=max(disMin[idx],i);
}
vector<int>anss(n+2,0);
int prev=1;
int prvVal=0;
// debug(mins);
int moves=1e9+10;
for(int i=0;i<m && prev<=n;i++){
    // debug(disMin[i]);
    //     debug(mins[i]);
    if(disMin[i]<prev){
        continue;
    }
    // debug(mins[i]);
    // debug(k);
    int ct=0;
    int mini=mins[i]-prvVal;
    // debug(mini);
    // while(k>=mini && ct<moves){
    //     k-=mini;
    //     anss[prev]++;
    //     anss[disMin[i]+1]--;
    //     ct++;
    // }
     ct=min(moves,k/mini);
    k-=(ct*mini);
    anss[prev]+=ct;
    anss[disMin[i]+1]-=ct;

    moves=min(moves,ct);
    prev=disMin[i]+1;
    prvVal+=mini;
    // debug(prev);
    // debug(k);
    // debug(prvVal);
}
for(int i=1;i<=n;i++){
    anss[i]+=anss[i-1];
    cout<<anss[i]<<" ";
}
cout<<endl;



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