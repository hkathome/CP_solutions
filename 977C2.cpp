#include <iostream>
#include <algorithm>
#include <bitset>
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

#define n_l '\n'
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: "; cerr << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cerr << to_string(H) << " | "; dbgm(T...); } 
#define dbgm(...) cerr << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cerr << endl
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

int n,m,q;
vector<int>a,b,idx;
vector<int>seg;
void build(int node,int s,int e){
    if(s==e){
        seg[node]=idx[b[s]];
        return;
    }
    int mid=(s+e)>>1;
    build(2*node+1,s,mid);
    build(2*node+2,mid+1,e);
    seg[node]=max(seg[2*node+1],seg[2*node+2]);
}
void update(int node,int s,int e,int idx,int val){
    if(s==e){
        seg[node]=val;
        return;
    }
    int md=(s+e)>>1;
    if(idx<=md){
        update(2*node+1,s,md,idx,val);
    }
    else{
        update(2*node+2,md+1,e,idx,val);
    }
    seg[node]=max(seg[2*node+1],seg[2*node+2]);

}
int query(int node,int s,int e,int l,int r){
    if(r<s || l>e){
        return -1;
    }
    if(l<=s && r>=e){
        return seg[node];
    }
    int mid=(s+e)>>1;
    return max(query(2*node+1,s,mid,l,r),query(2*node+2,mid+1,e,l,r));

}
void na(){
    cout<<"TIDAK"<<endl;
}
void ya(){
    cout<<"Ya"<<endl;
}
void solve(){
    cin>>n>>m>>q;
    a.clear();b.clear();a.resize(n),b.resize(m);
    idx.clear();idx.resize(n+1);
    seg.clear();
    seg.resize(4*m,-1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        idx[a[i]]=i;
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    build(0,0,m-1);
    set<int>notOk;
    bool f=false;
    for(int i=0;i<m;i++){
        int x=query(0,0,m-1,0,i-1);
        if(idx[b[i]]<=x){
            //ok
            continue;
        }
        else if(x+1<n && a[x+1]==b[i]){
            //ok;
        }
        else{
            f=true;
            notOk.insert(i);
        }
    }
    if(f){
        na();
    }
    else{
        ya();
    }
    while(q--){
        int si,ti;
        cin>>si>>ti;
        si--;
        int x=query(0,0,m-1,0,si-1);
        bool f1=false;
        if(idx[ti]<=x){
            f1=true;
        }
        else if(x+1<n && a[x+1]==ti){
            f1=true;
        }
        b[si]=ti;
        if(!f1){
            notOk.insert(si);
        }
        if(ti+1<=n){
            
        }
        update(0,0,m-1,si,idx[ti]);
        if(f1){
            while(!notOk.empty()){
                auto it=notOk.begin();
                if(*it<si){
                    break;
                }
                 x=query(0,0,m-1,0,*it-1);
                 if(idx[b[*it]]<=x){
                    notOk.erase(*it);
                 }
                 else if(x+1<n && a[x+1]==b[*it]){
                    notOk.erase(*it);
                 }
                 else{
                    break;
                 }
            }
        }
        if(notOk.empty()){
            ya();
        }
        else{
            na();
        }
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
  cin>>t;
  while(t--){
    solve();
  }
    
}