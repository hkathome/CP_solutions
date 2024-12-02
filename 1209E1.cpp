#include <bits/stdc++.h>
#include <set>
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
const int mod=998244353;
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
int n,m;
vector<vector<int>>mat;
int solve_case1(){
    //1 1 1 1 
    //getting best from each col
    vector<int>v;
    for(int j=1;j<=m;j++){
        int mxi=0;
        for(int i=1;i<=n;i++){
            mxi=max(mxi,mat[i][j]);
        }
        v.pb(mxi);
    }
    int ans=0;
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<min(n,(int)v.size());i++){
        ans+=v[i];
    }
    return ans;

}
int solve_case2(){
    //2 1 1 
    if(n<2){
        return 0;
    }
    //choosing one col
    int ans=0;
    for(int i=1;i<=m;i++){
        int ans1=0;
        int mxi1=-1;
        int mxi2=-1;
        for(int j=1;j<=n;j++){
            if(mat[j][i]>mxi1){
                mxi2=mxi1;
                mxi1=mat[j][i];
            }
            else if(mat[j][i]>mxi2){
                mxi2=mat[j][i];
            }
        }
        ans1+=(mxi1+mxi2);
        if(n==2){
            ans=max(ans,ans1);
            continue;
        }
         mxi2=0;
         mxi1=0;
        for(int k=1;k<=m;k++){
            if(k==i)continue;
            int mxi=0;
            for(int j=1;j<=n;j++){
                mxi=max(mxi,mat[j][k]);
            }
            if(mxi>mxi1){
                mxi2=mxi1;
                mxi1=mxi;
            }
            else if(mxi>mxi2){
                mxi2=mxi;
            }
        }
        if(n==3){
            ans1+=mxi1;
        }
        else if(n==4){
            ans1+=(mxi1+mxi2);
        }
        ans=max(ans,ans1);
    }
    return ans;
}
int solve_case3(){
    //2 2
    //choosing 2 cols
    if(n<4){
        return 0;
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        int ans1=0;
        int sum1=0;
        for(int k=1;k<=n;k++){
            if(mat[k][i]+mat[k%n+1][i]>sum1){
                sum1=mat[k][i]+mat[k%n+1][i];
            }
        }
        for(int j=i+1;j<=m;j++){
            //choosing ith & jth row
            int sum2=0;
            for(int k=1;k<=n;k++){
              if(mat[k][j]+mat[k%n+1][j]>sum2){
                sum2=mat[k][j]+mat[k%n+1][j];
            }
            }
            ans1=max(ans1,sum2);
        }
        ans=max(ans,ans1+sum1);
        
    }
      for(int i=1;i<=m;i++){
        int ans1=0;
        int sum1=0;
        for(int k=1;k<=n;k++){
            int nxt=k+2;
            if(nxt>4){
                nxt-=n;
            }
            if(mat[k][i]+mat[nxt][i]>sum1){
                sum1=mat[k][i]+mat[nxt][i];
            }
        }
        for(int j=i+1;j<=m;j++){
            //choosing ith & jth row
            int sum2=0;
            for(int k=1;k<=n;k++){
                 int nxt=k+2;
                 if(nxt>4){
                   nxt-=n;
                  }
                if(mat[k][j]+mat[nxt][j]>sum2){
                   sum2=mat[k][j]+mat[nxt][j];
                }
            }
            ans1=max(ans1,sum2);
        }
        ans=max(ans,ans1+sum1);
        
    }
    return ans;

}
int solve_case4(){
//3 1
if(n<3){
    return 0;
}
int ans=0;
for(int i=1;i<=m;i++){
    int ans1=0;
    int mxi1=0,mxi2=0,mxi3=0;
    for(int j=1;j<=n;j++){
        if(mat[j][i]>mxi1){
            mxi3=mxi2;
            mxi2=mxi1;
            mxi1=mat[j][i];
        }
        else if(mat[j][i]>mxi2){
            mxi3=mxi2;
            mxi2=mat[j][i];
        }
        else if(mat[j][i]>mxi3){
            mxi3=mat[j][i];
        }
    }
    ans1+=(mxi1+mxi2+mxi3);
    if(n==3){
        ans=max(ans,ans1);
        continue;
    }
    mxi1=0;
    for(int k=1;k<=m;k++){
        if(k==i)continue;
        for(int j=1;j<=n;j++){
            mxi1=max(mxi1,mat[j][k]);
        }
    }
    ans1+=mxi1;
    ans=max(ans,ans1);
}
return ans;

}
int solve_case5(){
    //4
    if(n<4){
        return 0;
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        int ans1=0;
        for(int j=1;j<=n;j++){
            ans1+=mat[j][i];
        }
        ans=max(ans,ans1);
    }
    return ans;
}
void solve(){
cin>>n>>m;
mat.clear();
mat.resize(n+1,vector<int>(m+1));
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        cin>>mat[i][j];
    }
}
//all four different cols
//1 col with 2 nums and other two from other cols
//2 cols each with 2 nums
//1 col with 3 nums other with 1
//1 col with all 4
int ans1=solve_case1();
int ans2=solve_case2();
int ans3=solve_case3();
int ans4=solve_case4();
int ans5=solve_case5();
int ans=max({ans1,ans2,ans3,ans4,ans5});
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
  int t=1;
  cin>>t;
  while(t--){
    solve();
  }
    
}