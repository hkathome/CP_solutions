#include <bits/stdc++.h>
#include <set>
#define ll long long 
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define debug(x) cerr<<#x<<" "<<x<<"\n";
#include <chrono>
#include <random>
using namespace std;
const int mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
const int inf=2e9;
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
void solve(){
int n;
cin>>n;
vector<pair<int,int>>v(n+1);
vector<pair<int,int>>vv(n+1);

for(int i=1;i<=n;i++){
    int l,r,c;
    cin>>l>>r>>c;
    v[i]={r,c};
    vv[i]={l,i};
}
sort(vv.begin()+1,vv.end());
set<pair<int,int>>st;
vector<int>ans(n+1,inf);
for(int i=1;i<=n;i++){
 if(st.empty()){
    st.insert(v[vv[i].se]);
    continue;
 }
 else{
    int mxr=v[vv[i].se].fi;
    while(st.size()>0 && (st.rbegin()->se)==v[vv[i].se].se){
        mxr=max(mxr,st.rbegin()->fi);
        auto it=st.end();
        it--;
    st.erase(it);
    }
    if(st.size()>0){
        auto it=st.rbegin();
        ans[vv[i].se]=max(0,vv[i].fi-it->fi);
    }
    st.insert({mxr,v[vv[i].se].se});
 }
 
}
st.clear();
for(int i=n;i>=1;i--){
    if(st.empty()){
        st.insert({vv[i].fi,v[vv[i].se].se});
        continue;
    }
    else{
        int minl=vv[i].fi;
        while(st.size()>0 && (st.begin()->se)==v[vv[i].se].se){
            minl=min(minl,st.begin()->fi);
            st.erase(st.begin());
        }
        if(st.size()>0){
            auto it=st.begin();
            ans[vv[i].se]=min(ans[vv[i].se],max(0,it->fi-v[vv[i].se].fi));//l-v[vv[i].se].fi
        }
        st.insert({minl,v[vv[i].se].se});
    }
}
for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
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