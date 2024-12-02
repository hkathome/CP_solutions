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
bool check(vector<int>&v){
    int n=v.size();
    int brp=n;
for(int i=1;i<n;i++){
        if(v[i]<v[i-1]){
            brp=i;
            break;
        }
    }
  
    vector<int>vv1;
    int j=brp;
    while(brp<n){
        vv1.pb(v[brp++]);
    }
    brp=j;
    for(int i=0;i<j;i++){
        vv1.pb(v[i]);
    }
    bool f= true;
    for(int i=1;i<n;i++){
        if(vv1[i]<vv1[i-1]){
            return false;
        }
    }
    return true;
}
int calcI(vector<int>&v){
        int n=v.size();
    int brp=n;
for(int i=1;i<n;i++){
        if(v[i]<v[i-1]){
            brp=i;
            break;
        }
    }
  
    vector<int>vv1;
    int j=brp;
    while(brp<n){
        vv1.pb(v[brp++]);
    }
    brp=j;
    for(int i=0;i<j;i++){
        vv1.pb(v[i]);
    }
    bool f= true;
    for(int i=1;i<n;i++){
        if(vv1[i]<vv1[i-1]){
            f=false;
            break;
        }
    }
    int ans=(n-brp);
    if(f){
        return ans;
    }
    else{
        return 1000000000;
    }
}
int calcD(vector<int>&v){
        int n=v.size();
    int brp=n;
for(int i=1;i<n;i++){
        if(v[i]>v[i-1]){
            brp=i;
            break;
        }
    }
  
    vector<int>vv1;
    int j=brp;
    while(brp<n){
        vv1.pb(v[brp++]);
    }
    brp=j;
    for(int i=0;i<j;i++){
        vv1.pb(v[i]);
    }
    bool f= true;
    for(int i=1;i<n;i++){
        if(vv1[i]>vv1[i-1]){
            f=false;
            break;
        }
    }
    int ans=(n-brp);
    if(f){
        return ans+1;
    }
    else{
        return 1000000000;
    }
}
void solve(){
    //1.increasing on its own->0 ops
    //2.becomes increasing after some right shifts i.e initially an increasing suffix and
    // then from point of decresing shift all els to right, then must become increasing, ans=no. of shifts
    //3. check if 2 is possible for reversed array
    // ans=min(calc(arr),calc(reverse(arr)));
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int brp=n;
    for(int i=1;i<n;i++){
        if(v[i]<v[i-1]){
            brp=i;
            break;
        }
    }
    if(brp==n){
        cout<<"0\n";
        return;
    }
    vector<int>v1=v;
    reverse(all(v1));
    bool f=check(v)| check(v1);
    if(!f){
        cout<<"-1\n";
        return;
    }
    int ans=min(min(calcI(v),calcD(v)),min(calcD(v1),calcI(v1))+1);
    cout<<ans<<endl;

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
