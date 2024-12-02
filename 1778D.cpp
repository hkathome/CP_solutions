#include <bits/stdc++.h>
#include <set>
#define ll long long 
#define pb push_back
#define pii pair<int,int>
#define debug(x) cerr<<#x<<" "<<x<<"\n"
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
//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 

const int N=1e6+10;
int p_inv[N];
void pInv(){
    for(int i=N-2;i>=0;i--){
        p_inv[i]=expo(i,mod-2);
    }
}
template <typename T>
T m_add(T a,T b){a+=b;while(a<0){a+=mod;}a%=mod;return a;}
template <typename T>
T m_mul(T a,T b){ll ans=1ll*a*b; return ans%mod;}
template <typename T>
T m_div(T a,T b){return m_mul<T>(a,p_inv[b]);}
void solve(){
int n;
cin>>n;
string a,b;
// debug(n);
cin>>a>>b;
int g=0;

for(int i=0;i<n;i++){
    g+=(a[i]!=b[i]);
}
// debug(n);
vector<vector<int>>dp(n+1,vector<int>(3));
dp[1][0]=1;
dp[1][1]=0;
// debug(a);
// debug(b);
// debug(g);
for(int k=1;k<n;k++){
  
    if(k==1){
    dp[k+1][0]=m_div<int>(n,n-k);
    dp[k+1][1]=m_add<int>(mod,-m_div<int>(n,(n-k)));

    }
    else{
        dp[k+1][0]=m_div<int>(m_add<int>(m_mul<int>(n,dp[k][0]),-1*m_mul<int>(k,dp[k-1][0])),n-k);
        dp[k+1][1]=m_div<int>(m_add<int>(m_add<int>(m_mul<int>(dp[k][1],n),-1*m_mul<int>(k,dp[k-1][1])),-1*n),n-k);
      //  debug("fwf");
    }
    //n*dp[k-1]-n-k*dp[k-2]=dp[k]*(n-k)
}
//dp[5] calculated in terms of dp[1] and we also have dp[5]=1+dp[4]

vector<int>ans(3);
ans[0]=m_add<int>(dp[n][0],-dp[n-1][0]);
ans[1]=m_add<int>(m_add<int>(dp[n-1][1],-dp[n][1]),1);
int xf=m_div<int>(ans[1],ans[0]);
//dp[1]=xf;

int my_ans=m_add<int>(m_mul<int>(dp[g][0],xf),dp[g][1]);
cout<<my_ans<<"\n";

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
    pInv();
  int t=1;
  cin>>t;
  while(t--){
    solve();
  }
    
}