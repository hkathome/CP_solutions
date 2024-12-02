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
#define all(x) (x).begin(),x.end()
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
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
vector<int>papa,Mxi;
void print_answer(vector<int>&qq){
    for(auto &z:qq){
        cout<<z<<" ";
    }
    cout<<endl;
}
int root(int x){
    if(papa[x]==x){
        return x;
    }
    return papa[x]=root(papa[x]);
}
void unite(int x,int y,int mxi){
    x=root(x);
    y=root(y);
    papa[y]=x;
    Mxi[x]=mxi;
}
void solve(){
int n,l,a,b,r;
cin>>n;
vector<pii>vv;
vector<pii>ports(n);
map<int,int>Mp;
for(int i=0;i<n;i++){
    cin>>l>>r>>a>>b;
    ports[i]={l,b};
    vv.pb({l,1});
    vv.pb({b,3});
    if(Mp.count(l)){
        Mp[l]=max(Mp[l],b);
    }
    else{
        Mp[l]=b;
    }
}
int q;
cin>>q;
vector<int>qq;
for(int i=0;i<q;i++){
    int x;
    cin>>x;
    qq.pb(x);
    vv.pb({x,2});
}
sort(all(vv));
int m=vv.size();
papa.clear();
papa.resize(m);
Mxi.clear();
Mxi.resize(m);
for(int i=0;i<m;i++){
    papa[i]=i;
    Mxi[i]=vv[i].fi;
}
 int i=0;
 while(i<m && vv[i].se==2){
    i++;
 }
 if(i>=m){
    print_answer(qq);//ans=qq[i];
    return;
 }
//  debug(i);
//  debug(vv);

 while(i<m){
   l=vv[i].fi;
 int j=i+1;
    int ct=1;
    int mxi=Mp[l];
    l=i;
    while(j<m && ct>0){
        if(vv[j].se==2){
            unite(l,j,mxi);
            // debug2(l,j);
            // debug(vv[j].fi);
            j++;
            continue;
        }
        else if(vv[j].se==3){
            ct--;
            j++;
            continue;
        }
        int l1=vv[j].fi;
        mxi=max(mxi,Mp[l1]);
        l1=j;
        unite(l,l1,mxi);
        ct++;
        l=l1;
        j++;
      //  debug2(j,ct);
    }
    // debug(i);
    i=j;
      while(i<m && vv[i].se==2){
        i++;
     }
 }
//  debug(Mxi);
for(int i=0;i<qq.size();i++){
    int dis=lower_bound(vv.begin(),vv.end(),make_pair(qq[i],2))-vv.begin();
    int p=root(dis);
    // debug2(qq[i],dis);
    // debug(p);
    cout<<Mxi[p]<<" ";

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