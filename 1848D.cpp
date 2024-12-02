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
ll sf;
ll calc(ll moves){
 ll toAdd=moves;
 toAdd*=(1ll*20);
ll ans=sf+toAdd;
 return ans;

}
void solve(){
ll s,k;

cin>>s>>k;
ll ans=1ll*s*k;
debug(ans);
ll lst=s%10;
if(lst==5){
    ll ans1=1ll*s*k;
    ans=max(ans1,1ll*(s+5)*(k-1));
    cout<<ans<<endl;
    return;
}
if(lst==0){
    cout<<1ll*s*k<<"\n";
    return;
}
ll k1=k;
if(lst%2==1){
    s+=(s%10);
    k1--;
    ans=max(ans,s*k1);
}
sf=s;
k=k1;
//for no step
for(int i=0;i<min(1ll*4,k);i++){
    ans=max(ans,s*k1);
ll l=0;
ll r=k1/4;
while(l<=r){
    ll md1=l+((r-l)/(1ll*3));
    ll md2=r-((r-l)/(1ll*3));
    ll v1=calc(md1)*1ll*(k1-4*md1);
    ll v2=calc(md2)*1ll*(k1-4*md2);
    if(v1<v2){
        l=md1+1;
        ans=max(ans,v2);
    }
    else{
        ans=max(ans,v1);
        r=md2-1;
    }
}
s+=(s%10);
sf=s;
k1--;
}


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