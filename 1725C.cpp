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

int expo(int a,int b){
    if(b==0)return 1;
    ll z=expo(a,b/2);
    z*=z;
    z%=mod;
    if(b&1){
        z*=a;
        z%=mod;
    }
    return z;
}
//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
const int N=3e5+10;
ll fact[N];
void fac(){
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(1ll*i*fact[i-1])%mod;
    }
}
int nCr(int n,int r){
    if(r>n){
        return 0;
    }
    ll a=fact[n];
    ll b=1ll*expo(fact[n-r],mod-2)*expo(fact[r],mod-2);
    b%=mod;
    a*=b;
    a%=mod;
    return a;
}
void solve(){
int n,m;
cin>>n>>m;

vector<int>D(n+1);
ll C=0;//Circumference
for(int i=1;i<=n;i++){
    cin>>D[i];
    C+=1ll*D[i];
}
//if C is odd then ans will be expo(M,N);
if(C&1){
    cout<<expo(m,n)<<"\n";
    return;
}
ll sum1=0,sum2=0;
int l=1;
int r=1;
C/=2;
vector<ll>dp(n+1);
vector<int>diameter(n+2,-1);
int p=0;//to count pairs of diametrically opposite points
while(r<=n && sum1<C){
    while(r<=n && sum2-sum1<C){
        sum2+=1ll*D[r];
        r++;
    }
    if(sum2-sum1==C){
        p++;
        diameter[r]=l;
    }
    sum1+=D[l];
    l++;
}
//we have two optios:
//1)for some pairs we choose same colour for both end-points,then we cannot choose that same colour for any other point
//2) then for other pairs both end-points are different and In this case we can use same colour for other points(other than its other end_point)
// let us say, we have i pairs then ways of doing this=C(p,i)*C(m,i)*fact[i]*((m-i)*(m-i-1))^(p-i)*(m-i)^(n-2*p)
ll ans=0;
for(int i=0;i<=p;i++){
 ll ans1=nCr(m,i)*fact[i];
 ans1%=mod;
 ans1*=nCr(p,i);
//  debug(nCr(m,i));
 ans1%=mod;
//  debug2(ans1,p);
 if(m>(i+1)){
    ans1%=mod;
    ans1*=expo((1ll*(m-i)*(m-i-1))%mod,p-i);
    // debug(ans1);
    ans1%=mod;
 }
 else if(p>i){
    ans1=0;
 }
//  debug(ans1);
//  debug2(m,i);
 ans1*=expo(m-i,n-2*p);
 ans1%=mod;
 ans+=ans1;
 ans%=mod;
}
cout<<ans<<"\n";





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
  fac();
 // cin>>t;
  while(t--){
    solve();
  }
    
}