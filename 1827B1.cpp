#include <bits/stdc++.h>
#include <set>
#define ll long long 
#define pb push_back
#define pii pair<int,int>
#define debug(x) cerr<<#x<<" "<<x<<"\n";
#define debug2(x,y) cerr<<#x<<" "<<x<<" "<<#y<<" "<<y<<"\n";
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
void debugv(vector<vector<int>>vv){
    int K=vv.size();
    for(int i=1;i<K;i++){
        for(int j=1;j<K;j++){
            debug2(i,j);
            debug(vv[i][j]);
        }
    }
}

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
const int M=15,N=5005;
const int inf=1e9;
 int Pow2[M];
int prv2[N];
vector<int>fwk;
int n;
void p2(){
    Pow2[0]=1;
    for(int i=1;i<M;i++){
        Pow2[i]=2*Pow2[i-1];
    }
    int prv=0;
    for(int i=1;i<N;i++){
        for(int j=0;j<M;j++){
            if(i==Pow2[j]){
                prv=j;
            }
        }
        prv2[i]=prv;

    }
}

void solve(){
cin>>n;
vector<int>a(n+1);
for(int i=1;i<=n;i++){
    cin>>a[i];
}
//how to find (l,k,r) such that max(l,k)<min(k+1,r), then (l,k) is isolated from (k+1,r)
//idea: let's say a[i] for k+1<=i<=r then to find l I need to find index of previous number lesser than a[i].
//let a[idx]<a[i] then by definition of k, k=idx
//next find the index of number greater than a[i] and index<k,than by  defn. it is l-1
//next find index of number less than a[i] and index>k,then by defn it is r+1
//number of subarrays covered=[k+1,i]is first subarray then (r-i) more, so r-i+1 total
//similarly [k] is first subarray then [k-l] more so k-l+1 total
//so total(r-i+1)*(k-l+1) subarrays
ll ans=0;
for(int i=1;i<n;i++){
    ans+=1ll*i*(n-i);
}
for(int i=2;i<=n;i++){
    int k=-1;
    for(int j=i-1;j>=1;j--){
        if(a[j]<a[i]){
            k=j;
            break;
        }
    }
    if(k==-1)continue;
  int l=k;
  while(l-1>=1 && a[l-1]<a[i]){
    l--;
  }
    int r=i;
    while(r+1<=n && a[r+1]>a[i]){
        r++;
    }
    ans-=1ll*(r-i+1)*(k-l+1);

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
  p2();
  cin>>t;
  while(t--){
    solve();
  }
    
}