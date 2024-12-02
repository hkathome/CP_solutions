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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n+1,vector<int>(m+1));
    vector<pii>mxis;
    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){
            cin>>mat[i][j];
          
        }
      
    }
    for(int j=1;j<=m;j++){
        int mxi=0;
        for(int i=1;i<=n;i++){
            mxi=max(mxi,mat[i][j]);
        }
        mxis.pb({mxi,j});
    }
    sort(mxis.begin(),mxis.end(),greater<pii>());
    vector<vector<int>>dp2;
    vector<int>dp1;
    dp2.resize(n,vector<int>(1<<n,0));
    dp1.resize((1<<n),0);
    // debug((int)mxis.size());
    // debug(mxis);
    for (int j1 = 0; j1 < min(n, (int)mxis.size()); j1++)
    {
        int j = mxis[j1].se;

        for (int rot = 0; rot < n; rot++)
        {
            for (int i1 = 1; i1 <= n; i1++)
            {
                int i = i1 + rot;
                i = (i <= n) ? i : i - n;
                for (int k = 0; k < (1 << n); k++)
                {
                     if((k&(1<<(i-1)))==0){
                        dp2[rot][k|(1<<(i-1))]=max({ dp2[rot][k|(1<<(i-1))],dp1[k|(1<<(i-1))],dp2[rot][k]+mat[i1][j],dp1[k]+mat[i1][j]});
                      }
                    else{
                        dp2[rot][k]=max(dp1[k],dp2[rot][k]);
                     }
                }
            }
        }
     //   debug(dp2);
        for(int k=0;k<(1<<n);k++){
            for(int l=0;l<n;l++){
                dp1[k]=max(dp1[k],dp2[l][k]);
            }
        }

    }
  
    cout<<dp1[(1<<n)-1]<<"\n";


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