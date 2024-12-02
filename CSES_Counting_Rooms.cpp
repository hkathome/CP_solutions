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
int dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};
void solve(){
int n,m;
cin>>n>>m;
vector<vector<char>>mat(n,vector<char>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>mat[i][j];
    }
}
map<int,char>Mp;
Mp[0]='U';
Mp[1]='D';
Mp[2]='L';
Mp[3]='R';
queue<pii>q;
vector<bool>vis(n*m,false);
auto ok=[&](int x,int y){
    return(!(x<0 || x>=n || y<0 || y>=m));
};
vector<vector<char>>dd(n,vector<char>(m));
vector<vector<pii>>papa(n,vector<pii>(m));
auto process=[&](int i,int j){
    q.push({i,j});
    vis[i*m+j]=true;
    while(!q.empty()){
        auto z=q.front();
        q.pop();
        for(int x1=0;x1<4;x1++){
            int x=z.fi+dir[x1][0];
            int y=z.se+dir[x1][1];
            if(ok(x,y) && !vis[x*m+y] && mat[x][y]!='#'){
                vis[x*m+y]=true;
                q.push({x,y});
                papa[x][y]={z.fi,z.se};
                dd[x][y]=Mp[x1];
            }
        }
    }
};
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(mat[i][j]!='A'){
            continue;
        }
        process(i,j);

    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       if(mat[i][j]=='B' && vis[i*m+j]){
        cout<<"YES\n";
        vector<char>anss;
        while(mat[i][j]!='A'){
            anss.pb(dd[i][j]);
            int i1=papa[i][j].fi;
            int j1=papa[i][j].se;
            i=i1;j=j1;
        }
        cout<<anss.size()<<endl;
        reverse(all(anss));
        trav(z,anss){
            cout<<z;
        }
        return;
       }
    }
}
cout<<"NO\n";



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