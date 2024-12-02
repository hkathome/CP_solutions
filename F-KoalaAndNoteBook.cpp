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
#define deb(x) cerr<<#x<<" "<<x<<"\n";
#define debug2(x,y) cerr<<#x<<" "<<x<<" "<<#y<<" "<<y<<"\n";
#include <chrono>
#include <random>
using namespace std;
const int mod=1e9+7;
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
const int N=12e5+10, M=20;
int n,m;
vector<vector<pii>>adj;
vector<int>ans;

// int process_nodes(vector<int>&vv){

//  int k=vv.size();
//  vector<bool>done(k,false);
//  for(int i=M-1;i>=0;i--){
//     vector<int>grps,ancs;
//     for(int j=0;j<vv.size();j++){
//         if(done[j]){
//             continue;
//         }
//         int anc=up[vv[j]][i];
//         ancs.pb(anc);
//     }
//     sort(ancs.begin(),ancs.end());
//     ancs.erase(unique(ancs.begin(),ancs.end()),ancs.end());
//     if(ancs.size()==1){
//         continue;
//     }
//     grps.resize(ancs.size(),-1);
//     for(int j=0;j<vv.size();j++){
//         if(done[j]){
//             continue;
//         }
//         int anc=up[vv[j]][i];
//         int idx=lower_bound(ancs.begin(),ancs.end(),anc)-ancs.begin();
//         if(grps[idx]==-1){
//             grps[idx]=vv[j];
//         }
//     }
//     //now I have all groups here. Now I have to find the best group.
//     int j=1;
//     int cur=grps[0];
//     while(j<grps.size()){
//         int cur1=cur;
//         int other=grps[j];
//         for(int l=i;l>=0;l--){
//             int anc1=up[cur][l];
//             int anc2=up[other][l];
//             if(anc1!=anc2){
//                 cur=anc1;
//                 other=anc2;
//             }
//         }
//         if(best[cur]<best[other]){
//             cur=cur1;
//         }
//         else{
//             cur=grps[j];
//         }
//         j++;
//     }
//     for(j=0;j<vv.size();j++){
//         if(done[j]){
//             continue;
//         }
//         int anc=up[vv[j]][i];
//         int idx=lower_bound(ancs.begin(),ancs.end(),anc)-ancs.begin();
//         if(grps[idx]!=cur){
//             done[j]=true;
//         }
        
//     }
//  }
//  int best_pa=-1;
//  int mini=1e9+10;
//  for(int i=0;i<k;i++){
//     if(!done[i]){
//         if(best[vv[i]]<mini){
//             mini=best[vv[i]];
//               best_pa=vv[i];
//         }
//      }
//  }
//  //debug("end");
//  return best_pa;

// }
// inline int get_size(int x){
//     int len=0;while(x>0){x/=10;len++;} return len;
// }
inline void cal_ans(int node ,int best_pa,int val){
    ans[node]=(1ll*(1ll*ans[best_pa]*10)%mod+1ll*val)%mod;

}
vector<int>dis,visf;
void bfs(int s){
    //first I need to accumulate all parent nodes for any shortest path to a particular node
    //depends on number of edges; so O(m)
    vector<bool>vis(n+1,false);
    dis.resize(n+1,mod);
    queue<int>q;
    q.push(1);
    vis[1]=true;
    dis[1]=0;
 

     // debug("level");
    while(!q.empty()){
      int x=q.front();
      q.pop();
      for(auto &z:adj[x]){
        if(!vis[z.se]){
            q.push(z.se);
            vis[z.se]=true;
            dis[z.se]=dis[x]+1;
        }
      }
  
  }
}
int pos[N];
void dfs(vector<int>&vv){
    
    for(int val=0;val<10;val++){
        vector<int>uu;
        for(int s:vv){
          while(pos[s]<adj[s].size() && adj[s][pos[s]].fi==val){
            auto z=adj[s][pos[s]];
            if(z.fi==val && dis[z.se]==dis[s]+1 && ans[z.se]==-1 ){
                cal_ans(z.se,s,z.fi);
                uu.pb(z.se);
            }
            pos[s]++;
          }
          
       }
        if(!uu.empty())dfs(uu);
    }

}
void add(int u,int v,int x){
    int cur=v;
 while(x>9){
    adj[++n].pb({x%10,cur});
    x/=10;
    cur=n;
 }
 adj[u].pb({x,cur});
}
void solve(){
    int n1;
    cin>>n>>m;
    n1=n;
    adj.clear();
    adj.resize(N+1);
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
       add(x,y,i);
       add(y,x,i);
        
    }
ans.clear();
ans.resize(n+1,-1);
for(int i=1;i<=n;i++){
    sort(adj[i].begin(),adj[i].end());
}
bfs(1);

ans[1]=0;
vector<int>vv1;
vv1.pb(1);
dfs(vv1);
for(int i=2;i<=n1;i++){
    cout<<ans[i]<<"\n";
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

 // cin>>t;
  while(t--){
    solve();
  }
    
}