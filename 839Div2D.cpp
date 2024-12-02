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


//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 

void solve(){
int n,k;
cin>>n>>k;
string s1;
cin>>s1;
string s=" "+s1;
//dp1[i][k1]=largest 1-substring in prefix of i using k1 flips
//dp2[i][k1]=largest 1-substring in suffix of i using k1 flips
vector<int>pre(n+1,0);
for(int i=1;i<=n;i++){
    pre[i]=pre[i-1]+(s[i]=='1');
}
vector<vector<int>>dp1[2],dp2[2];
for(int j=0;j<2;j++){
    dp1[j].resize(n+1,vector<int>(k+1,0));
    dp2[j].resize(n+2,vector<int>(k+1,0));
}

for(int i=1;i<=n;i++){
    for(int j=0;j<=k;j++){
        if(j>0){
          dp1[0][i][j]=max(s[i]=='1'?dp1[0][i-1][j]+(s[i]=='1'):0,s[i]=='0'?dp1[0][i-1][j-1]+(s[i]=='0'):0);
          dp1[1][i][j]=max(dp1[1][i-1][j],dp1[0][i][j]);
        }
        else{
            if(s[i]=='1'){
            dp1[0][i][j]=dp1[0][i-1][j]+(s[i]=='1');
            }
             dp1[1][i][j]=max(dp1[0][i][j],dp1[1][i-1][j]);
        }
    }
}
for(int i=n;i>=1;i--){
     for(int j=0;j<=k;j++){
      if(j>0){
          dp2[0][i][j]=max(s[i]=='1'?dp2[0][i+1][j]+(s[i]=='1'):0,s[i]=='0'?dp2[0][i+1][j-1]+(s[i]=='0'):0);
          dp2[1][i][j]=max(dp2[1][i+1][j],dp2[0][i][j]);
        }
        else{
            if(s[i]=='1'){
            dp2[0][i][j]=dp2[0][i+1][j]+(s[i]=='1');
            }
             dp2[1][i][j]=max(dp2[0][i][j],dp2[1][i+1][j]);
        }
    }
}
// debug(dp1[0]);
// debug(dp2[0]);
vector<int>vv(n+1,-1);
for(int l=1;l<=n;l++){
    for(int r=l;r<=n;r++){
        //make (l,r) a 0-substring
        int ones=(pre[r]-pre[l-1]);
        if(ones>k){
            break;
        }
        int l0=r-l+1;
        int l1=max(dp1[1][l-1][k-ones],dp2[1][r+1][k-ones]);
        vv[l0]=max(vv[l0],l1);
    }
}
vv[0]=dp1[1][n][k];
// debug(vv);
vector<int>ansf(n+1,0);
for(int i=0;i<=n;i++){
    if(vv[i]==-1){
        continue;
    }
    int l=1;
    int r=n;
    while(l<=r){
        int md=l+(r-l)/2;
        if(md*i+vv[i]<ansf[md]){
            l=md+1;
        }
        else{
            r=md-1;
        }
    }
    for(int j=l;j<=n;j++){
        ansf[j]=j*i+vv[i];
    }
}
for(int i=1;i<=n;i++){
    cout<<ansf[i]<<" ";
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