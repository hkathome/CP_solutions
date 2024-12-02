#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#include <stack>
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
ll expo(ll a, ll b) {
    if (b == 0) {return 1;}
    ll z = expo(a, b / 2); z *= z; z %= mod; if (b % 2 != 0) {z *= a; z %= mod;}
    return z;
}
ll gcd(ll a, ll b) {
    if (a == 0)return b;
    return gcd(b % a, a);
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

void solve(){
    // int n,m;
    // cin>>n>>m;
    // char s1[n+1],s2[m+1];
    // scanf("%s",s1+1);
    // scanf("%s",s2+1);
    // debug(s1);
    // debug(s2);
    
    // int dp[n+1][m+1];
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         dp[i][j]=0;
    //     }
    // }
    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(s1[i]==s2[j]){
    //             dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
    //         }
    //         else{
    //             dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
    //         }
    //     }
    // }
    // cout<<dp[n][m]<<"\n";
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    char A[n1+1],B[n2+1],C[n3+1];
    scanf("%s",A+1);
     scanf("%s",B+1);
      scanf("%s",C+1);

      int dp[n1+1][n2+1][n3+1];
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int k=0;k<=n3;k++){
                dp[i][j][k]=0;
            }
        }
    }
    debug(A);
    debug(B);
    debug(C);
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            for(int k=1;k<=n3;k++){
                if(A[i]==B[j] && A[i]==C[k]){
                    dp[i][j][k]=max(dp[i][j][k],1+dp[i-1][j-1][k-1]);
                }
                else{
                    dp[i][j][k]=max({dp[i][j][k],dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1],
                        dp[i-1][j-1][k],dp[i-1][j][k-1],dp[i][j-1][k-1],dp[i-1][j-1][k-1]
                    });
                }
            }
        }
    }
     for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int k=0;k<=n3;k++){
                debug(dp[i][j][k]);
            }
        }
    }
    cout<<dp[n1][n2][n3]<<"\n";
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