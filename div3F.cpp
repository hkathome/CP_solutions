#include <bits/stdc++.h>
#include <set>
#include <map>
#define ull unsigned long long 
#define lld long double
#define ll long long 
#define pb push_back
#define pii pair<int,int>
#define pil pair<ll,ll>
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
const ll inf=1ll*3e9;

//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
ll Sqrt(ll D){
    if(D<0){
        return -1;
    }
    ll l=0;
    ll r=inf;
    while(l<=r){
        ll md=l+(r-l)/(1ll*2);
        if(md*md<D){
            l=md+1;
        }
        else{
            r=md-1;
        }
    }
    if(1ll*l*l==D){
        return l;
    }
    return -1;
}
pil ask(ll x,ll y){
    ll D=1ll*x*x-1ll*4*y;
    ll p=Sqrt(D);
    // debug(D);
    // debug(p);
    if(p==-1){
        return {-inf,-inf};
    }
    ll x1=(x+p);
    ll x2=(x-p);
    if(x1%2){
        x1=-inf;
        x2=-inf;
    }
    else{
        x1/=(1ll*2);
        x2/=(1ll*2);
    }
 //  debug2(x1,x2);
    return {x1,x2};


}
void solve(){
    debug(inf);
int n;
cin>>n;
map<ll,ll>Mp;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    Mp[x]++;
}
// for(auto &z:Mp){
//     cout<<z.fi<<" "<<z.se<<"\n";
// }
int q;
cin>>q;
while(q--){
    ll x,y;
    cin>>x>>y;
    pil z=ask(x,y);
    if(z.fi==-inf){
        cout<<"0 ";
    }
    else{
        // assert(z.se==(x-z.fi));
  
        ll ans=0;
        if(z.fi==z.se){
            // debug2(z.fi,z.se);
            // debug(Mp[z.fi]);
            if(Mp.count(z.fi)){
                ans=1ll*Mp[z.fi]*(Mp[z.fi]-1);
                ans/=(1ll*2);
            }
            
        }
        else{
            ll ans1=(Mp.count(z.fi)?Mp[z.fi]:0);
            ll ans2=(Mp.count(z.se)?Mp[z.se]:0);
            debug(ans1);
            debug(ans2);
            ans=1ll*ans1*ans2;
        }
        cout<<ans<<" ";
    }
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