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
#define all(x) (x).begin(),(x).end()
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
const int N=1e6+10;

//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
int prime[N];
vector<int>primes;
void sieve(){
    prime[1]=1;
    for(int i=2;i*i<N;i++){
        if(prime[i]){
            continue;
        }
        for(int j=i*i;j<N;j+=i){
            if(!prime[j]){
                prime[j]=i;
            }
        }
    }
    for(int i=1;i<N;i++){
        if(prime[i]==0){
            primes.pb(i);
        }
    }

}
int getCount(int n,int x){
    int ct=0;
    while(n%x==0){
        ct++;
        n/=x;
    }
    return ct;
}
int getCount1(int &n,int x){
    int ct=0;
    while(n%x==0){
        ct++;
        n/=x;
    }
    return ct;
}
void solve(){
int n,q;
cin>>n>>q;
//debug(n);
//cout<<n<<endl;
int dd=1;
int n1=n;
vector<int>vv((int)primes.size());
//debug(primes);
for(int i=0;i<primes.size();i++){
    int x=primes[i];
    if(n1%x==0){
        int ct1=getCount1(n1,x);
        vv[i]=ct1;
        dd*=(ct1+1);
     //   debug(ct1+1);
    }
}
int d1=dd;
//debug(dd);
vector<int>vv1(all(vv));

while(q--){
    int ty,x1;
    cin>>ty;
 //   debug(ty);
    if(ty==1){
    cin>>x1;
    for(int i=0;i<primes.size();i++){
    int x=primes[i];
    if(x1%x==0){
     //   debug(x);
        d1/=(vv1[i]+1);
       vv1[i]+=getCount(x1,x);
       d1*=(vv1[i]+1);
    }
    }
    // for(int i=0;i<primes.size();i++){//this can be optimized if needed we can update d1 in prev loop only
    //     d1*=(vv1[i]+1);
    // }
  //  debug(d1);
    bool f=true;
    int d2=d1;
    for(int i=0;i<primes[i];i++){
        int x=primes[i];
        if(d1%x==0){
            int ct=getCount1(d1,x);
            if(vv1[i]<ct){
                f=false;
                break;
            }
        }
    }
    if(d1>1 || !f){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
    }
    d1=d2;

  }
  else{
    vv1=vv;
    d1=dd;
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
    sieve();
  int t=1;
  cin>>t;
  while(t--){
    solve();
  }
    
}