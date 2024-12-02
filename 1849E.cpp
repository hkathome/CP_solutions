#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
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
const int inf=1e9+10;
const int N=1e6+10;
const int M=21;

//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
int n;
vector<int>v;
vector<vector<int>>sp;
void build_sp(){
    sp.clear();
    sp.resize(n+1,vector<int>(M,inf));
    for(int i=n;i>=1;i--){
        sp[i][0]=min(v[i],(i<n?v[i+1]:inf));
        for(int j=1;j<M;j++){
            int papa=i+(1<<(j-1));
            sp[i][j]=min(sp[i][j-1],papa<=n?sp[papa][j-1]:inf);
        }
    }
    debug(sp);

}
void solve(){
cin>>n;
v.clear();
v.resize(n+1);
for(int i=1;i<=n;i++){
    cin>>v[i];
}
// build_sp();
//next max and last max
vector<int>prev(n+1,0),nexs(n+1,n+1);
stack<int>st;
for(int i=1;i<=n;i++){
 while(!st.empty() && v[st.top()]<=v[i]){
    st.pop();
 }
 prev[i]=(!st.empty()?st.top():0);
 st.push(i);
}
while(!st.empty()){
    st.pop();
}
for(int i=n;i>=1;i--){
 while(!st.empty() && v[st.top()]>=v[i]){
    st.pop();
 }
 nexs[i]=(!st.empty()?st.top():n+1);
 st.push(i);
}

//max_element_pos>min_element_pos
ll ans=0;
for(int i=1;i<=n;i++){
    int l=prev[i]+1;
    ans+=(1ll*(i-l));
    int r=nexs[i]-1;
    ans+=(1ll*(r-i));
}
debug(ans);
vector<int>vv;
for(int i=n;i>=1;i--){
    while(!vv.empty() && v[vv.back()]<=v[i]){
        vv.pop_back();
    }
    int x=nexs[i]-1;
    int l=0;
    int r=vv.size()-1;
    while(l<=r){
        int md=l+(r-l)/2;
        if(vv[md]>x){
            l=md+1;
        }
        else{
            r=md-1;
        }
    }
    int ans1=(int)(vv.size());
    ans1-=(l);
    ans-=max(0ll,1ll*(ans1));
    vv.pb(i);

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
 // cin>>t;
  while(t--){
    solve();
  }
    
}