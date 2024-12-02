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
// int n,m;
// vector<int>v;
// bool ok(int x){
//     long long sum=0;
//     for(int i=0;i<n;i++){
//         long long val=(v[i]/x);
//         if(v[i]%x!=0){
//             val++;
//         }
//         sum+=val;
//     }
//     return (sum<=m);
// }
// void solve(){
//     cin>>n;
//     v.resize(n);
//  for(int i=0;i<n;i++){
//     cin>>v[i];
//  }
//  cin>>m;
//  int l=0;//l<ans
//  int r=1e7;//r>=ans
//  while(r-l>1){
//     int md=(r+l)/2;
//     if(ok(md)){
//         r=md;
//     }
//     else{
//         l=md;
//     }
//  }
//  cout<<r<<"\n";

// }
// int getMaxVowels(string s,int k){
//     int n=s.size();
//     vector<char>vows={'a','e','i','o','u'};
//     vector<int>v(5,0);
//     map<char,int>Mp;
//     for(int i=0;i<5;i++){
//         Mp[vows[i]]=i;
//     }
//     for(int i=0;i<k;i++){
//         if(Mp.count(s[i])){
//             v[Mp[s[i]]]++;
//         }
//     }
//     int ans=v[0]+v[1]+v[2]+v[3]+v[4];
//     int l=0;
//     for(int i=k;i<n;i++){
//         if(Mp.count(s[i])){
//             v[Mp[s[i]]]++;
//         }
//         if(Mp.count(s[l])){
//             v[Mp[s[l]]]--;
//         }
//         l++;
//         ans=max(ans,v[0]+v[1]+v[2]+v[3]+v[4]);
//     }
//     return ans;
    

// }
// vector<string> generatePermutations(string s){
//     int n=s.size();
//     vector<int>letterPos(n,0);
//     int l=0;
//     vector<string>ans;
//     for(int i=0;i<n;i++){
//         if(s[i]<='z' && s[i]>='a'){
//             letterPos[i]=l++;
//         }
//     }
//     for(int mask=0;mask<(1<<l);mask++){
//         string s1=s;
//         for(int i=0;i<n;i++){
//             if(s[i]<='z' && s[i]>='a'){
//                 if((mask>>letterPos[i])&1){
//                     s1[i]=s[i]-'a'+'A';
//                 }
//             }
//         }
//         ans.push_back(s1);
//     }
//     return ans;
// }
// #define ll long long 
// int main(){
//     int n;
//     cin>>n;
//     vector<ll>v(n+1,0);
//     vector<ll>pre(n+1,0);
//     for(int i=1;i<=n;i++){
//         cin>>v[i];
//         pre[i]=pre[i-1]+v[i];
//     }
//     stack<int>lastGreater;
//     vector<ll>dp(n+1,-1);
//     dp[0]=0;
//     for(int i=1;i<=n;i++){
//         int prv=-1;
//         while(!lastGreater.empty() && v[lastGreater.top()]<v[i]){
//             prv=lastGreater.top();
//             lastGreater.pop();
//         }
//         if(!lastGreater.empty()){
//             int prv=lastGreater.top();
//             dp[i]=max(dp[i-1],dp[prv]+min(v[prv],v[i])*(i-prv)-(pre[i]-pre[prv]));
//         }
//         else{
//             if(prv==-1){
//             dp[i]=dp[i-1];
//             }
//             else{
//                 dp[i]=max(dp[i-1],dp[prv]+min(v[prv],v[i])*(i-prv-1)-(pre[i-1]-pre[prv]));
//             }
//         }
//         lastGreater.push(i);
//     }
//     cout<<dp[n]<<"\n"; 
// }
// int n;
// vector<int>bit;
// int sum(int idx) {
// 	int total=0;
// 	while(idx>0){
// 	total+=bit[idx];
// 	idx-=(idx&(-idx));
// 	}
// 	return total;
// }

// void update(int idx, int val) {
// 	while(idx<=n){
// 	bit[idx]+=val;
// 	idx+=(idx&(-idx));
// 	}
// }

// int range_sum(int l,int r){
// 	return(sum(r)-sum(l-1));
// }
// int main(){
//     cin>>n;
//     vector<int>v(n+1);
//     bit.resize(n+1,0);
//     for(int i=1;i<=n;i++){
//         cin>>v[i];
//         v[i]%=2;
//         update(i,v[i]);
//     }
//     int q;
//     cin>>q;
//     while(q--){
//         int ty,x,y;
//         cin>>ty>>x>>y;
//         if(ty==0){
//             //update
//             y%=2;
//             int delta=y-v[x];
//             if(delta==0){
//                 continue;
//             }
//             else{
//                 update(x,delta);
//             }
//         }
//         else if(ty==1){
//             //even
//             cout<<(y-x+1)-range_sum(x,y)<<"\n";
//         }
//         else{
//             cout<<range_sum(x,y)<<"\n";
//         }
//     }

    
// }
#define ll long long
int mod1=1e9+7;
void solve(){
    int n;
    cin>>n;
    vector<ll>v(n+1);
    map<int,ll>Mp;
    ll ct1=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]==1){
            ct1++;
            continue;
        }
        bool f=true;
        for(int j=2;j*j<=v[i];j++){
            if(v[i]%j==0){
                f=false;
                break;
            }
        }
        if(f){
            Mp[v[i]]++;
        }
    }
    if(Mp.empty()){
        cout<<"0\n";
    }
    else{
    long long ans=1;
    for(auto z:Mp){
        ans*=(z.ss+1);
        ans%=mod1;
    }
    ans--;
    if(ans<0){
        ans+=mod1;
    }
    ll p=1;
    while(ct1--){
        p*=(1ll*2);
        p%=mod1;
    }
    ans*=p;
    ans%=mod1;
    cout<<ans<<"\n";

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
  //cin>>t;
  while(t--){
    solve();
  }
    
}