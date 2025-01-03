#include <bits/stdc++.h>
#include <set>
#include <queue>
#include <map>
#define ull unsigned long long 
#define lld long double
#define ll long long 
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
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
int dp[1024];
const int inf=1e8;
int n,m;
vector<int>days;
vector<string>rem,causes;
int solve(int mask){
priority_queue<pii,vector<pii>,greater<pii> >pq;
pq.push(mp(0,mask));
vector<bool>vis(1024,false);
dp[mask]=0;
while(!pq.empty()){
    pii z=pq.top();
    pq.pop();
    if(vis[z.se]){continue;}
    vis[z.se]=true;
    for(int i=0;i<m;i++){
        int newMask=z.se;
        for(int j=0;j<n;j++){
            if(rem[i][j]=='1' && (newMask&(1<<j))){
                newMask^=(1<<j);
            }
            if(causes[i][j]=='1'){
                newMask|=(1<<j);
            }
        }
        if(dp[newMask]==-1 || dp[newMask]>(z.fi+days[i])){
            dp[newMask]=z.fi+days[i];
            pq.push(make_pair(dp[newMask],newMask));
        }
    }
}

return dp[0];



}
void solve1(){
    cin>>n>>m;
    days.clear();rem.clear();causes.clear();
    days.resize(m);rem.resize(m);causes.resize(m);
    string s;
    cin>>s;
    for(int i=0;i<m;i++){
        cin>>days[i];
        cin>>rem[i];
        cin>>causes[i];
    }
    memset(dp,-1,sizeof(dp));
  
   
    int st=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            st|=(1<<i);
        }
    }
   
   int ans=solve(st);
   int mxi=1e6+10;
   if(ans>mxi){
    cout<<"-1\n";
    return;
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
    solve1();
  }
    
}