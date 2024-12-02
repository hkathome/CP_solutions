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
#define mp make_pair
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
vector<int>v,seg,segMin,segMax,v1;
void build(int node,int s,int e){
    if(s>e)return;
    if(s==e){
        // seg[node]=(v[s]==-1?mod:v[s]);
        segMin[node]=segMax[node]=v1[s];
        return;
    }
    int mid=(s+e)>>1;
    build(2*node+1,s,mid);build(2*node+2,mid+1,e);
    // seg[node]=min(seg[2*node+1],seg[2*node+2]);
    segMin[node]=min(segMin[2*node+1],segMin[2*node+2]);
    segMax[node]=max(segMax[2*node+1],segMax[2*node+2]);
}
void update(int node,int s,int e,int pos,int val){
    if(s>e)return;
    if(s==e){
        seg[node]=val;
        return;
    }
    int mid=(s+e)>>1;
    if(pos<=mid){
        update(2*node+1,s,mid,pos,val);
    }
    else{
        update(2*node+2,mid+1,e,pos,val);
    }
    seg[node]=min(seg[2*node+1],seg[2*node+2]);
}
void update1(int node,int s,int e,int pos){
    if(s>e)return;
    if(s==e){
        segMin[node]=mod;
        segMax[node]=-1;
        return;
    }
    int mid=(s+e)>>1;
    if(pos<=mid){
        update1(2*node+1,s,mid,pos);
    }
    else{
        update1(2*node+2,mid+1,e,pos);
    }
     segMin[node]=min(segMin[2*node+1],segMin[2*node+2]);
    segMax[node]=max(segMax[2*node+1],segMax[2*node+2]);
}
int query(int node,int s,int e,int l,int r){
    if(r<s || l>e){
        return mod;
    }
    if(l<=s && r>=e){
        return seg[node];
    }
    int mid=(s+e)>>1;
    return min(query(2*node+1,s,mid,l,r),query(2*node+2,mid+1,e,l,r));
}
int queryMin(int node,int s,int e,int l,int r){
      if(r<s || l>e){
        return mod;
    }
    if(l<=s && r>=e){
        return segMin[node];
    }
    int mid=(s+e)>>1;
    return min(queryMin(2*node+1,s,mid,l,r),queryMin(2*node+2,mid+1,e,l,r));
}
int queryMax(int node,int s,int e,int l,int r){
      if(r<s || l>e){
        return -1;
    }
    if(l<=s && r>=e){
        return segMax[node];
    }
    int mid=(s+e)>>1;
    return max(queryMax(2*node+1,s,mid,l,r),queryMax(2*node+2,mid+1,e,l,r));
}
void solve(){
//tc-> O(n*(2logn(update)+logn(query)+log(n)(lower_bound)))=O(4nlogn)=4*3*1e5*18=~3*1e7
 int n;
 cin>>n;
 v1.clear();v1.resize(n);
 segMin.clear();segMax.clear();
 segMin.resize(4*n,mod);segMax.resize(4*n,-1);
 vector<int>adj[n];
 set<int>st;
for(int i=0;i<n;i++){
    cin>>v1[i];
    st.insert(v1[i]);
    adj[v1[i]-1].pb(i);
}
build(0,0,n-1);
int n1=st.size();
vector<int>ans;
int l=0;
int r=-1;
int tn=0;
while(ans.size()<n1){
    int prev=l;
    // debug(prev);
    if(tn==0){
        // debug(tn);
        // debug2(l,r);
        //new movement
        if(l>r){
        l=r+1;
        while((l<n && ((v1[l]==-1 || adj[v1[l]-1].back()>l)))){
            l++;
        }
        r=l;
        // if(r==n){
        //     break;
        // }
        //debug(r);
        int mxi=queryMax(0,0,n-1,prev,r);
        assert(mxi!=-1);
        auto it=lower_bound(all(adj[mxi-1]),prev);
        ans.pb(mxi);
        // debug(mxi);
        trav(z,adj[mxi-1]){
            v1[z]=-1;
            update1(0,0,n-1,z);
        }
        if(v1[r]==-1){
            l=r+1;
            while((l<n && ((v1[l]==-1 || adj[v1[l]-1].back()>l)))){
                l++;
            }
            r=l;
        }
        l=*it+1;
        }
        else{
            int mxi=queryMax(0,0,n-1,prev,r);
           
            if(mxi==-1){
                //debug("here1");
                //debug2(prev,r);
                l=r+1;
                //keeping tn same
                continue;
            }
             ans.pb(mxi);
            //  debug(mxi);
             auto it=lower_bound(all(adj[mxi-1]),prev);
            trav(z,adj[mxi-1]){
                v1[z]=-1;
              update1(0,0,n-1,z);
            }
        if(v1[r]==-1){
            l=r+1;
            while((l<n && ((v1[l]==-1 || adj[v1[l]-1].back()>l)))){
                l++;
            }
            r=l;
         }
            l=*it+1;
        }
    }
    else{
        // debug(tn);
        // debug2(l,r);
             //new movement
        if(l>r){
        l=r+1;
        while((l<n && ((v1[l]==-1 || adj[v1[l]-1].back()>l)))){
            l++;
        }
        r=l;
        //debug2(prev,r);
        int mini=queryMin(0,0,n-1,prev,r);
        // debug(mini);
        assert(mini!=mod);
        auto it=lower_bound(all(adj[mini-1]),prev);
        ans.pb(mini);
        trav(z,adj[mini-1]){
            v1[z]=-1;
            update1(0,0,n-1,z);
        }
        if(v1[r]==-1){
            l=r+1;
            while((l<n && ((v1[l]==-1 || adj[v1[l]-1].back()>l)))){
                l++;
            }
            r=l;
          }   
        l=*it+1;
        }
        else{
            int mini=queryMin(0,0,n-1,prev,r);
            if(mini==mod){
                //debug("here2");
                //debug2(prev,r);
                l=r+1;
                //keeping tn same
                continue;
            }
            // debug(mini);
             ans.pb(mini);
             auto it=lower_bound(all(adj[mini-1]),prev);
            trav(z,adj[mini-1]){
                v1[z]=-1;
              update1(0,0,n-1,z);
            }
            // debug(v1[r]);
        if(v1[r]==-1){
            l=r+1;
            while((l<n && ((v1[l]==-1 || adj[v1[l]-1].back()>l)))){
                l++;
            }
            r=l;
          } 
            l=*it+1;
        }
    }
    tn^=1;
}
cout<<ans.size()<<"\n";
trav(z,ans){
    cout<<z<<" ";
}
cout<<"\n";


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