#include <iostream>
#include <algorithm>
#include <bitset>
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

#define n_l '\n'
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: "; cerr << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cerr << to_string(H) << " | "; dbgm(T...); } 
#define dbgm(...) cerr << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cerr << endl
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
int n,n_max=0;
vector<int>arr[3],vv[3],seg;
const int M=3;
    void build(int node, int s, int e,vector<int>&v) {
        if (s == e) {
            seg[node] = v[s];
            return;
        }
        int md = (s + e) >> 1;
        build(2 * node + 1, s, md,v);
        build(2 * node + 2, md + 1, e,v);
        seg[node] = max(seg[2 * node + 1] , seg[2 * node + 2]);
    }
    void update(int node, int s, int e, int pos, int val) {
        if (s > e)return;
        if (s == e) {
            seg[node] = val;
            return;
        }
        int md = (s + e) >> 1;
        if (pos <= md) {
            update(2 * node + 1, s, md, pos, val);
        }
        else {
            update(2 * node + 2, md + 1, e, pos, val);
        }
        seg[node] = max(seg[2 * node + 1] , seg[2 * node + 2]);
    }
    int query(int node, int s, int e, int l, int r) {
        if (r < s || l > e)return -1;
        if (l <= s && r >= e)return seg[node];
        int md = (s + e) >> 1;
        return (max(query(2 * node + 1, s, md, l, r) ,query(2 * node + 2, md + 1, e, l, r)));
    }
void solve(int tt){
cin>>n;
n_max=max(n,n_max);
for(int i=0;i<3;i++){
    arr[i].clear();
    arr[i].resize(n);
    vv[i].clear();vv[i].resize(n);
}
for(int i=0;i<3;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
       arr[i][j]--;
        vv[i][arr[i][j]]=j;
    }
}
//dbg(n);
//dp[i] to store {idx1,idx2} s.t. a[idx1]<a[i] 
// vector<vector<int>>dp1(3,vector<int>(n+1));
// auto dp2=dp1;
// for(int i=0;i<3;i++){
//     for(int j=0;j<n;j++){
//         dp1[i][arr[i][j]]=arr[(i+1)%3][j];
//     }
//   //  dbg(dp1[i]);
//     seg.clear();
//     seg.resize(4*n,-1);
//     build(0,0,n-1,dp1[i]);
//     for(int j=0;j<n;j++){
//         dp1[i][j]=query(0,0,n-1,0,arr[i][j]-1);
//         update(0,0,n-1,arr[i][j],-1);
//     }
//    //dbg(dp1[i]);
//     for(int j=0;j<n;j++){
//         dp2[i][arr[i][j]]=arr[(i+2)%3][j];
//     }
//   //  dbg(dp2[i]);
//     seg.clear();
//     seg.resize(4*n,-1);
//     build(0,0,n-1,dp2[i]);
//     for(int j=0;j<n;j++){
//         dp2[i][j]=query(0,0,n-1,0,arr[i][j]-1);
//         update(0,0,n-1,arr[i][j],-1);
//     }
// //    dbg(dp2[i]);
    
// }
 vector<int>adj[3*n];
vector<int>anss;
auto calc=[&](int idx){
    anss.clear();
for(int i=0;i<3*n;i++){
    adj[i].clear();
} 
int x=idx*n;
priority_queue<int,vector<int>,greater<int>>q;
q.push(x);
vector<bool>vis(3*n,false);
vis[x]=true;
set<int>st[3];
for(int i=0;i<3;i++){
    st[i].clear();
    for(int j=0;j<n;j++){
        st[i].insert(j);
    }
}
int ptr[3];
ptr[0]=0;
ptr[1]=0;
ptr[2]=0;

while(!q.empty()){
    auto z=q.top();
    q.pop();
    int idxf=z/n;
  //dbg(idxf);
   // dbg(z);
   while(ptr[idxf]<n && ptr[idxf]<z%n){
    if(st[idxf].count(arr[idxf][ptr[idxf]])){
        st[idxf].erase(arr[idxf][ptr[idxf]]);
    }
    ptr[idxf]++;
   }
   while(!st[idxf].empty()){
    auto it=st[idxf].begin();
    if(*it>=arr[idxf][z%n]){
        break;
    }
   // dbg(*it);
    int idx1=vv[idxf][*it];
    //dbg(idx1);
    if(!vis[idx1+((idxf+1)%3)*n]){
    adj[z].pb(idx1+((idxf+1)%3)*n);
    q.push(idx1+((idxf+1)%3)*n);
    vis[idx1+((idxf+1)%3)*n]=true;
    }
    if(!vis[idx1+((idxf+2)%3)*n]){
    adj[z].pb(idx1+((idxf+2)%3)*n);
    q.push(idx1+((idxf+2)%3)*n);
    vis[idx1+((idxf+2)%3)*n]=true;
    }
    st[idxf].erase(it);
   }
    
}
// for(int i=0;i<3*n;i++){
//     dbgm(i,adj[i]);
// }
vector<int>dis(3*n,-1);
vis.clear();
vis.resize(3*n,false);
 x=(idx)*n;
vis[x]=true;

dis[x]=0;
queue<int>q1;
q1.push(x);
vector<int>pa(3*n,-1);
while(!q1.empty()){
    auto z=q1.front();
    q1.pop();
    trav(z1,adj[z]){
        if(!vis[z1]){
            dis[z1]=dis[z]+1;
            q1.push(z1);
            vis[z1]=true;
            pa[z1]=z;
        }
    }
}
for(int i=0;i<3*n;i++){
    if(dis[i]==-1){
        dis[i]=mod;
    }
}
int cur=-1;
if(dis[n-1]==dis[2*n-1] && dis[n-1]==dis[3*n-1] && dis[n-1]==mod){
    return mod;
}
if(dis[n-1]<dis[2*n-1] && dis[n-1]<dis[3*n-1]){
    cur=n-1;
}
else if(dis[2*n-1]<dis[3*n-1]){
    cur=2*n-1;
}
else{
    cur=3*n-1;
}

while(cur!=-1){
    anss.pb(cur);
    cur=pa[cur];
}
//dbg(anss);
return (int)anss.size();
};
vector<int>ansf;
int bst=3*n+5;
for(int idx=0;idx<3;idx++){
int len=calc(idx);
if(len<bst){
    ansf.clear();
    ansf=anss;
    bst=len;
}
}
if(bst==3*n+5){
    cout<<"NO"<<n_l;
    return;
}
// if(n_max>=20){
//     return;
// }
cout<<"YES"<<n_l;
cout<<bst-1<<n_l;
reverse(all(ansf));
vector<char>cc(3);
cc[0]='q';
cc[1]='k';
cc[2]='j';
for(int i=1;i<ansf.size();i++){
    int prv=ansf[i-1];
    cout<<cc[prv/n]<<" "<<(ansf[i]%n)+1<<n_l;
}


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
  int j=0;
  while(j<t){
    solve(j++);
  }
    
}