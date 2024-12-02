#include <bits/stdc++.h>
#include <set>
#include <map>
#include <queue>
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

void solve(){
int n;
cin>>n;
int len=n*(n+1);
len/=2;
vector<int>ans(len);
if(n%2==0){
  int l=0;
  int r=len-1;
  debug(r);
  int a=n;
  int b=(n-1)/2;
  while(b--){
    ans[l++]=n-1;
    ans[l++]=n;
  }
  b=n/2;
  while(b--){
    ans[r--]=n;
    ans[r--]=n-1;
  }
  ans[r--]=n;
int x=n-2;
  while(l<r && x>2){
    b=(x-1)/2;
    while(b--){
        ans[l++]=x;
        ans[l++]=x-1;
    }
    b=x/2;
    while(b--){
        ans[r--]=x;
        ans[r--]=x-1;
    }
    ans[r--]=x;
    x-=2;
  }
  ans[l++]=2;
  ans[l++]=1;
  ans[l++]=2;
assert(l==r+1);
}
else{
   int l=0;
  int r=len-1;
  int a=n;
  int b=(n-1)/2;
  while(b--){
    debug2(l,n-1);
    ans[l++]=n-1;
    debug2(l,n);
    ans[l++]=n;
  }
  b=n/2;
  while(b--){
    debug2(r,n);
    ans[r--]=n;
    debug2(r,n);
    ans[r--]=n-1;
  }
  ans[r--]=n;
int x=n-2;
  while(l<r && x>1){
    b=(x-1)/2;
    while(b--){
        ans[l++]=x;
        ans[l++]=x-1;
    }
    b=x/2;
    while(b--){
        ans[r--]=x;
        ans[r--]=x-1;
    }
    ans[r--]=x;
    x-=2;
  }
  ans[l++]=1;
    assert(l==(r+1));
}

for(auto z:ans){
cout<<z<<" ";
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
 // cin>>t;
  while(t--){
    solve();
  }
    
}