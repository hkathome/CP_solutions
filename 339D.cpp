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
int n;
vector<string>mat;
vector<vector<int>>dis[2];
int dp[20][20][20][20][120];
int dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool isOk(int x,int y){
    if(x<0 || y<0 || x>=n || y>=n){
        return false;
    }
    if(mat[x][y]=='#'){
        return false;
    }
    return true;
}

void bfs(int idx,pii p){
    dis[idx].clear();dis[idx].resize(n,vector<int>(n,mod));
    queue<pii>q;
    q.push(p);
    dis[idx][p.ff][p.ss]=0;
    while(!q.empty()){
        auto z=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=z.ff+dir[i][0];
            int y=z.ss+dir[i][1];
            if(isOk(x,y) && dis[idx][x][y]>(dis[idx][z.ff][z.ss]+1)){
                dis[idx][x][y]=dis[idx][z.ff][z.ss]+1;
                q.push({x,y});
            }
        }
    }
}
int solve1(int x1,int y1,int x2,int y2,int moves){
    if(x1==x2 && y1==y2){
        return 0;
    }
    if(moves>120){
        return -mod;
    }
    if(dp[x1][y1][x2][y2][moves]!=-1){
        return dp[x1][y1][x2][y2][moves];
    }
    int ans=mod;
      for(int i=0;i<4;i++){
            int x=x1+dir[i][0];
            int y=y1+dir[i][1];
            int xx=x2+dir[i][0];
            int yy=y2+dir[i][1];
            if(!isOk(x,y)){
                x=x1;
                y=y1;
            }
            if(!isOk(xx,yy)){
                xx=x2;
                yy=y2;
            }
            if(xx==x2 && yy==y2 && x1==x && y1==y){
                continue;
            }
            ans=min(ans,1+solve1(x,y,xx,yy,moves+1));
            
        }
       return (dp[x1][y1][x2][y2][moves]=ans);
}
void solve(){
    cin>>n;
    mat.clear();
    mat.resize(n);
    pii p1={-1,-1};
    pii p2=p1;
    for(int i=0;i<n;i++){
        cin>>mat[i];
        for(int j=0;j<n;j++){
            if(mat[i][j]=='P'){
                if(p1.ff!=-1){
                    p2={i,j};
                }
                else{
                    p1={i,j};
                }
            }
        }
    }
    memset(dp,-1,sizeof(dp));
   cout<<solve1(p1.ff,p1.ss,p2.ff,p2.ss,0)<<"\n";


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
  //cin>>t;
  while(t--){
    solve();
  }
    
}