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
int Len[1000005];
vector<vector<int>>vv(1000005);
void getLen(){
    int prev=0;
    int p=10;
    for(int j=1;j<=6;j++){
        for(int i=prev;i<p;i++){
            Len[i]=j;
        }
        prev=p;
        p*=10;
    }
    for(int i=1;i<=1000000;i++){
        int x=i;
        while(x>0){
            vv[i].pb(x%10);
            x/=10;
        }
        reverse(all(vv[i]));
    }

}
bool check(int i,int a,int b,int n){
    int len=Len[i];
    assert(len==vv[i].size());
    int j=0;
    int x=0;
    int j1=0;
    int iter=0;
    while(j<len){
        if(vv[i][j]==vv[n][j1]){
            j++;
            j1++;
        }
        else{
            return false;
        }
        if(j1==vv[n].size()){
            j1=0;
            iter++;
        }
    }
    return true;

}
void solve(){
    int n;
    cin>>n;
    int val2=n-Len[n];
    vector<pii>ans;
    if(n==1){
        for(int a=2;a<=10000;a++){
            ans.pb({a,a-1});
        }
    }
    for(int i=2;i<1000000;i++){
        int val1=i-Len[i];
        assert(val1>0);
        if(val2==0){
            //no solution
            continue;
        }
        else if(val1%val2==0){
            int a=val1/val2;
            int b=n*a-i;
            if(a>=1 && a<=10000 && b>=1 && b<=min(10000,n*a)){
                if(check(i,a,b,n)){
                    ans.pb({a,b});
                }
            }
        }
    }
    cout<<ans.size()<<"\n";
    trav(z,ans){
        cout<<z.ff<<" "<<z.ss<<"\n";
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
    getLen();
  int t=1;
  cin>>t;
  while(t--){
    solve();
  }
    
}