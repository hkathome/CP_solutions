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

void solve(){
string s;
cin>>s;
debug(s);
vector<vector<int>>v(5,vector<int>(5,0));
vector<int>vals={1,10,100,1000,10000};
int n=s.size();
vector<vector<bool>>pres(n+1,vector<bool>(5,false));
vector<int>ct(5,0);
for(int i=n-1;i>=0;i--){
    for(int j=0;j<5;j++){
        pres[i][j]=((s[i]-'A')==j || pres[i+1][j]);
    }
    
}
ll ans=0;
for(int i=0;i<n;i++){
    bool f=false;
    for(int j=(s[i]-'A')+1;j<5;j++){
        if(pres[i+1][j]){
            f=true;
            break;
        }
    }
   int ans1=(f?-1*vals[s[i]-'A']:vals[s[i]-'A']);
   ans+=1ll*ans1;
}
debug(ans);
ll ansf=ans;
for(int i=0;i<n;i++){
    vector<int>effect(5,0);
    for(int j=0;j<5;j++){
        int h=0;
        for(int k=j+1;k<5;k++){
            h=max(h,v[k][j]);
            //k+'A' se piche kitna j+'A' hai
        }
        effect[j]=ct[j]-h;//only if j se bada aage nhi hai
        for(int k=j+1;k<5;k++){
            if(pres[i+1][k]){
                effect[j]=0;
                break;
            }
        }
    }
    debug(effect);
    ll ans1=ans;
    for(int j=0;j<(s[i]-'A');j++){
        ans1+=2ll*effect[j]*vals[j];
    }
    debug(ans1);
    bool f=false;
      for(int k=(s[i]-'A')+1;k<5;k++){
            if(pres[i+1][k]){
                f=true;
                break;
            }
        }
        if(f){
            ans1+=1ll*vals[s[i]-'A'];
        }
        else{
             ans1-=1ll*vals[s[i]-'A'];
        }
        debug(ans1);
    for(int j=0;j<5;j++){
        ll ans2=ans1;
        debug(j);
        debug(ans2);
        for(int k=0;k<j;k++){
            debug(effect[k]);
             ans2-=2ll*effect[k]*vals[k];
         }
         debug(ans2);
         f=false;
           for(int k=j+1;k<5;k++){
            if(pres[i+1][k]){
                debug2(i,k);
                f=true;
                break;
            }
        }
        if(f){
            ans2-=vals[j];
        }
        else{
            ans2+=vals[j];
        }
        debug2(j,ans2);
         ansf=max(ansf,ans2);
    }


    //update ct
        ct[s[i]-'A']++;
    for(int j=0;j<5;j++){
        v[s[i]-'A'][j]=ct[j];
    }
}

cout<<ansf<<endl;



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