#include <iostream>
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

const int inf=1e9;
//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
const int M=6000;
void solve(){
string s;
cin>>s;
int n=s.size();
string s1=" "+s;
vector<vector<int>>dp[2*n+1];
for(int i=0;i<=2*n;i++){
    dp[i].resize(n+1,vector<int>(2*M+1,inf));
}
int dif=0,ones=0,zeros=0;
for(int i=0;i<n;i++){
    if(s[i]=='0'){
        dif+=ones;
        zeros++;
    }
    else{
        dif-=zeros;
        ones++;
    }
}
debug(n);
 assert(dif%2==0);
 //debug(dif);
dif/=2;
dp[n][0][M]=0;
for(int i=1;i<=n;i++){
    for(int j=0;j<=2*M;j++){
        for(int k=0;k<=2*n;k++){
        if(dp[k][i-1][j]!=inf){
            dp[k][i][j]=min(dp[k][i-1][j],dp[k][i][j]);
            if(s1[i]=='1'){
                assert(j+i<=2*M);
                dp[k+1][i][j+i]=min(min(dp[k+1][i-1][j+i],dp[k+1][i][j+i]),dp[k][i-1][j]+1);
            }
            else if(s1[i]=='0'){
                assert(j>=i);
                assert(k>0);
                dp[k-1][i][j-i]=min(min(dp[k-1][i-1][j-i],dp[k-1][i][j-i]),dp[k][i-1][j]+1);
            }
        }
      }
    }
}
debug2(dp[n][n][M-dif],dp[n][n][M+dif]);
cout<<dp[n][n][M-dif]/2<<endl;


}
int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("error.txt", "w", stderr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  int t=1;
  //cin>>t;
  while(t--){
    solve();
  }
    
}