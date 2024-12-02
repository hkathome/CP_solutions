#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mod=1e9+7;

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
vector<int>v(n+1,0);
for(int i=1;i<=n;i++){
    cin>>v[i];
}

vector<int>dp(n+1,0);
vector<int>p(n+1,0);
p[0]=1;
for(int i=1;i<=n;i++){
    p[i]=2*p[i-1];
    p[i]%=mod;
}
for(int i=1;i<n;i++){
    vector<int>dp1(i+1,0);
    vector<int>dp2(i+1,0);
    int j=i;
    int k=j;
    while(j>=1){
        int d1=v[i]-v[j];
        int d2=v[j]-(k>=1?v[k]:0);
        while(k>=1 && d2<=d1){
            k--;
            if(k>=1){
                d2=v[j]-v[k];
            }
        }
        //[k+1,j]
        dp1[j]=j-k;
        ll ans1=p[dp1[j]-1]-1;
        if(ans1<0){
            ans1+=mod;
        }
        ans1*=1ll*p[k];
        ans1%=mod;
        dp2[j]=ans1;
        // cerr<<j<<" "<<dp1[j]<<endl;
        assert(dp2[j]>=0);
        j--;
    }
    for(int j1=1;j1<=i;j1++){
        dp2[j1]+=dp2[j1-1];
        // cerr<<j1<<" "<<dp2[j1]<<endl;
        dp2[j1]%=mod;
    }
    k=i;
    for(j=i+1;j<=n;j++){
        int dis=v[j]-v[i];
        //no dl>dis, so v[i]-v[h]>dis
        int d1=v[i]-v[k];
        int ans1=0;
        while(k>=1 && d1<=dis){
            k--;
            d1=v[i]-v[k];  
        }
        ll ans=(dp2[k]+1)%mod;;
        ans*=1ll*p[n-j];
        ans%=mod;
        dp[i]+=ans;
        dp[i]%=mod;

        
    }
}
ll ans=0;
for(int i=1;i<=n;i++){
    ans+=dp[i];#pragma region #pragma region #pragma region 
    // cerr<<dp[i]<<" ";
    ans%=mod;
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

    solve();
    
}