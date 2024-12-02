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
const int N=2e5+10;
vector<int>primes;
int prime[N];
void sieve(){
    prime[1]=1;
    for(int i=2;i*i<N;i++){
        if(prime[i]){
            continue;
        }
        for(int j=i*i;j<N;j+=i){
            if(!prime[j]){
                prime[j]=i;
            }
        }
    }
    for(int i=2;i<N;i++){
        if(!prime[i]){
            primes.pb(i);
        }
    }
}
void solve(){
int n;
cin>>n;
if(n==1){
    cout<<"1\n";
    return;
}
if(n==2){
    cout<<"2 1\n";
    return;
}
vector<int>v(n,-1);
int l=0;
int r=n-1;
int i=0;
int tn=1;
vector<int>mark(n+1,false);
while(l<=r && primes[i]<=n){
    if(tn){
        mark[primes[i]]=true;
    v[l++]=primes[i++];
    tn^=1;
    }
    else{
        mark[primes[i]]=true;
        v[r--]=primes[i++];
        tn^=1;
    }
}
i=2;
v[(r+l)/2]=1;
while(l<=r){
    if(v[l]!=-1){
        l++;
        continue;
    }
    if(!mark[i]){
        v[l++]=i;
    }
    i++;
}
for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
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
  sieve();
  cin>>t;
  while(t--){
    solve();
  }
    
}