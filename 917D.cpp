
#include <iostream>
#include <map>
#include <set>
#include <cstring>
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
int expo(ll a,ll b,int MOD=mod){
    a%=MOD;
    if(b==0){
        return 1;
    }
    ll z=expo(a,b/(1ll*2),MOD);
    z*=z;
    z%=MOD;
    if(b&1ll){
        z*=a;
        z%=MOD;
    }
    return z;
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
int N=4e5+10; // maximum value possible in array b
 int Mxi=N-1;
vector<int>fwk;
void update(int idx,int val){
    //make sure 1<=idx<N;
    while(idx<N){
        fwk[idx]+=val;
        idx+=(idx&(-idx));
    }
}
int getSum(int idx){
    int s=0;
    while(idx>0){
        s+=fwk[idx];
        idx-=(idx&(-idx));
    }
    return s;
}
ll findInversions(vector<int>&v){
    int n=v.size();
     fwk.clear();
    fwk.resize(N,0);
    ll ans=0;
    bool isZero=false;
    for(int i=0;i<n;i++){
        isZero|=(v[i]==0);
    }
    for(int i=n-1;i>=0;i--){
        if(isZero){
            v[i]++;//incrementing all els by 1 to make all nos>=1;
        }
        ans+=getSum(v[i]-1);
        ans%=mod;
        update(v[i],1);
        if(isZero){
            v[i]--;  //returning back to original state;
        }
    }
    return ans;
    
}
void solve(){
    int n,k;
    cin>>n>>k;
    N=max(3*n,k)+10;
    Mxi=N-1;
  
    vector<int>p(n),q(k);
    vector<bool>avail(k,false);
    vector<int>pre(k+1,0);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int j=0;j<k;j++){
        cin>>q[j];
        avail[q[j]]=true;
        pre[q[j]]++;
    }
    for(int i=1;i<k;i++){
        pre[i]+=pre[i-1];
    }
    
    
    ll ans1=findInversions(q);
   
   fwk.clear();
   fwk.resize(N,0);

    ll p2=1;
    vector<ll>sum1(21,0),sum2(21,0);
    for(int i=n-1;i>=0;i--){
        p2=1;
        for(int j=0;j<21;j++){
            ll val=min(1ll*Mxi,1ll*p2*p[i]);
            sum1[j]+=1ll*getSum(val-1);
              sum1[j]%=mod;
              p2*=2;
        }
        update(p[i],1);
      

    }
   
    p2=1;
    for(int j=0;j<21;j++){
        fwk.clear();
        fwk.resize(N,0);
        for(int i=n-1;i>=0;i--){
            ll val=min(1ll*Mxi,1ll*p[i]*p2);
            sum2[j]+=1ll*getSum(p[i]-1);sum2[j]%=mod;
            update(val,1);
        }
        p2*=2;
    }
    
    ll ans=0;
    // debug(sum1);
    // debug(sum2);
    for(int i=0;i<k;i++){
        for(int j=q[i];j>=max(0,q[i]-19);j--){
            int dif=q[i]-j;
            
            ans+=sum1[dif];
            ans%=mod;
            
        }
        int x=q[i]-20;
        if(x>=0){
        ll k1=sum1[20]*1ll*pre[x];
        k1%=mod;
        ans+=k1;
        ans%=mod;

        }
        for(int j=q[i]+1;j<=min(k-1,(q[i]+19));j++){
            int dif=j-q[i];
            
            ans+=sum2[dif];
            ans%=mod;
        
        }    
    }

    // debug(ans);
    ans1*=1ll*n;
    ans1%=mod;
    ans+=ans1;
    ans%=mod;
    cout<<ans<<endl;
    fwk.clear();
    


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