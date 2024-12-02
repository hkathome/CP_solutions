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

const int N=1e6+10;
//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
int expo(int a,int b,int M){
    if(b==0){
        return 1;
    }
    ll z=expo(a,b/2,M);
    z*=z;
    z%=M;
    if(b%2){
        z*=a;
        z%=M;
    }
    return z;

}
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
int x,q,M;
vector<int>primes;
int prime[N];
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
    for(int i=2;i<N;i++){
        if(!prime[i]){
            prime[i]=i;
            primes.pb(i);
        }
    }
}
void solve(){
    cin>>x>>q>>M;
    //x=initial coordinate, q= number of queries, M=prime number
    //only primes of x>1e6 and their product won't change as they won't come again in x1,x2,etc
    vector<int>factors(N,0);
    int i=0;
    ll ans=1;
    int fs=0,evs=0;
    sieve();
   // debug(primes);
    while(x>1 && i<primes.size()){
        int p=primes[i];
        while(x%p==0){
            factors[p]++;
            x/=p;
        }
        if(p>2){
        ans*=1ll*(factors[p]+1);
        // debug(p);
        // debug(factors[p]);
        // debug(ans);
        ans%=M;
        }
        i++;
    }
    
    if(x>1e6){
    ans*=(1ll*2);
    ans%=M;
    }
  
    vector<ll>anss;
    set<int>zeros;
    while(q--){
        int xi;
        cin>>xi;
         debug(xi);
        while(prime[xi]!=xi){
            int p=prime[xi];
            int prev=factors[p];
            while(xi%p==0){
                factors[p]++;
                xi/=p;
            }
            if(p>2){
                if(!zeros.count(p)){
                ans*=(prev>0?1ll*expo(prev+1,M-2,M):1ll);
                  ans%=M;
                debug(p);
                debug("divide");
                debug(prev+1);
                debug(ans);
                }
                if((factors[p]+1)%M!=0){
                    if(zeros.count(p)){
                        zeros.erase(p);
                    }
                ans*=1ll*(factors[p]+1);
                ans%=M;
               debug(factors[p]);
               debug(ans);
                }
                else{
                  zeros.insert(p);

                }
            }
        }

        if(xi>1){
           int p=prime[xi];
            int prev=factors[p]; 
            factors[p]++;
            debug(p);
             if(p>2){
                if(!zeros.count(p)){
                ans*=(prev>0?1ll*expo(prev+1,M-2,M):1ll);
                ans%=M;
                }
                 if((factors[p]+1)%M!=0){
                      if(zeros.count(p)){
                        zeros.erase(p);
                    }
                    ans*=1ll*(factors[p]+1);
                    ans%=M;
                 }
                 else{
                    zeros.insert(p);
              
                 }
            }
         
        }
     
    if(zeros.empty()){
     anss.pb(ans);
    }
    else{
        anss.pb(0);
    }

    }

for(auto &ansf:anss){
    cout<<ansf<<"\n";
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