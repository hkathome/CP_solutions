#include <bits/stdc++.h>
#include <set>
#define ll long long 
#define pb push_back
#define pii pair<int,int>
#define debug(x) cerr<<#x<<" "<<x<<"\n";
using namespace std;
const int mod=998244353;

int expo(int a,int b){
    if(b==0)return 1;
    ll z=expo(a,b/2);
    z*=z;
    z%=mod;
    if(b&1){
        z*=1ll*a;
        z%=mod;
    }
    return z;
}
int nodes=0;
int edges=0;
int self_loop=0;
vector<vector<int>>adj;
vector<bool>vis,vis1;
void dfs(int s){
    vis[s]=true;
    nodes++;
    bool ans=false;
    for(auto &z:adj[s]){
        edges++;
        if(!vis[z]){
            dfs(z);
        }
        if(z==s){
            self_loop++;
        }
    }
    
}
void solve(){
int n;
cin>>n;
vector<int>a(n),b(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
    cin>>b[i];
}

//for answer to exist for each component there must exist a cycle in that component
adj.clear();
adj.resize(n+1);
int ct=0;

for(int i=0;i<n;i++){
  adj[a[i]].pb(b[i]);
  adj[b[i]].pb(a[i]);
//   debug(a[i]);
//   debug(b[i]);
    
}
int p=0;
vis.clear();
vis.resize(n+1,false);
for(int i=1;i<=n;i++){
    if(!vis[i]){
        nodes=0;
        edges=0;
        self_loop=0;
        // debug(i);
        // debug(edges);
         dfs(i);
        if(edges!=2*nodes){
            cout<<"0\n";
            return;
        }

        if(self_loop){
            ct++;
        }
        else{
        p++;
         }
    }
}
// cerr<<p<<" "<<ct<<endl;
ll ans=1ll*expo(n,ct)*expo(2,p);
ans%=mod;
cout<<ans<<"\n";


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
    int t;
    cin>>t;
    while(t--){
    solve();
    }
   
    
}