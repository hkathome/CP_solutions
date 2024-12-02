#include <bits/stdc++.h>
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
bool check1(int n,string s){
    int ct1=0;
    for(int i=0;i<n && ct1>=0;i++){
        if(s[i]=='('){
            ct1++;
        }
        else{
            ct1--;
        }
    }
    int ct2=0;
    for(int i=0;i<n && ct2>=0;i++){
        if(s[i]==')'){
            ct2++;
        }
        else{
            ct2--;
        }
    }
    return(ct1>=0 || ct2>=0);
}
void solve(){
int n;
cin>>n;
string s;
cin>>s;
int ctO=0;//ctOpening=>'('
int ctC=0;//ctClosing=>')'
for(int i=0;i<n;i++){
    if(s[i]=='('){
        ctO++;
    }
    else{
        ctC++;
    }
}
if(ctO!=ctC){
    cout<<"-1\n";
    return;
}
if(check1(n,s)){
    cout<<"1\n";
    for(int i=0;i<n;i++){
        cout<<1<<" ";
    }
    cout<<endl;
    return;
}
vector<bool>color(n,0);
int ct=0;
vector<int>suf(n+1,0);
for(int i=n-1;i>=0;i--){
    suf[i]=(s[i]==')')+suf[i+1];
}
for(int i=0;i<n;i++){
    if(s[i]=='(' && suf[i]>ct){
        // debug(i);
        // debug(suf[i]);
        // debug(ct);
        color[i]=1;
        ct++;
    }
    else if(s[i]==')' && ct>0){
        ct--;
        color[i]=1;
    }

}
cout<<2<<endl;
for(int i=0;i<n;i++){
    if(color[i]){
        cout<<"1 ";
    }
    else{
        cout<<"2 ";
    }
}
cout<<endl;

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