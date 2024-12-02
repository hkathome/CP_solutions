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
const int M=55;
ll f[M];
void compute_fibonaci(){
    f[0]=1;
    f[1]=1;
    for(int i=2;i<M;i++){
        f[i]=f[i-1]+f[i-2];
    }
}

//sum be must be a fibonacci sum
//each chunk must be a fibonacci sum of alternate fibonacci numbers
void solve(){
int k;
cin>>k;
vector<int>C(k+1);
ll sum=0;
for(int i=1;i<=k;i++){
    cin>>C[i];
    sum+=1ll*C[i];
}
int i=0;
while(sum>0 && i<M){
    sum-=f[i];
    i++;
}
if(sum!=0){
   // debug("1");
    cout<<"No\n";
    return;
}
int lst_idx=i-1;
int prev=-1;
for(int i=lst_idx;i>=0;i--){
    int x=*max_element(C.begin()+1,C.end());
   // debug2(x,f[i]);
    if(x<f[i]){
      //  debug("3");
        cout<<"No\n";
        return;
    }
    bool f1=false;
    for(int j=1;j<=k;j++){
        if(C[j]==x && j!=prev){
            C[j]-=f[i];
            prev=j;
            f1=true;
            break;
        }
    }
    if(!f1){
      //  debug("2");
        cout<<"No\n";
        return;
    }
}
cout<<"Yes\n";




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
  compute_fibonaci();
  cin>>t;
  while(t--){
    solve();
  }
    
}