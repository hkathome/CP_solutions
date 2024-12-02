#include <iostream>
#include <vector>
#define ll long long 
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
const int K=90000;
int n;
vector<int>a;
vector<vector<int>>dp(302,vector<int>(2*K+1,-1));
int solve(int idx,int val){
    if(idx>=n){
        return 1;
    }
    if(dp[idx][val+K]!=-1){
        return dp[idx][val+K];
    }
    int i=idx;
    int ans=solve(idx+1,a[i+1]-val);
    if(val!=0){
    ans+=solve(idx+1,a[i+1]+val);
    }
    ans%=mod;
    return dp[idx][val+K]=ans;
}
void solve(){
    cin>>n;
   a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
 
    int ans=solve(2,a[2]);
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

    solve();
    
}