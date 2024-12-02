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
ll m;
cin>>n>>m;
vector<ll>dp(n+1,0);//dp[x] stores number of pairs with gcd=x
for(int x=n;x>=2;x--){
    int k=(n/x);
    //kC2 is number of possible edges
    dp[x]=1ll*k*(k-1);
    dp[x]/=(1ll*2);
    for(int j=2*x;j<=n;j+=x){
        dp[x]-=dp[j];//subtracting number of pairs having gcd p*k for 2<=p<=n/k
    }
}

int x=n;
ll cost=m;
while(x>1 && m>0){
    // debug2(x,dp[x]);
    // debug(cost);
    if(dp[x]<(x-1)){
        x--;
        continue;
    }
    ll steps=dp[x]/(1ll*(x-1));
    // debug(steps);
    if(1ll*steps*(x-1)<=m){
        cost+=steps;
        m-=(1ll*steps*(x-1));
    }
    else{
        steps=m/(1ll*(x-1));
        cost+=steps;
        m-=(1ll*steps*(x-1));
    }
    // //(cost);
    x--;

}
if(m>0){
    //not possible
    cout<<"-1\n";
}
else{
    cout<<cost<<"\n";
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
  while(t--){
    solve();
  }
    
}