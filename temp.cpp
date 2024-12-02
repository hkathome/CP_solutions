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
int n;
vector<int>seg1,seg2;
vector<int>a,b;
 vector<int>pre[2],suf[2];
void build(int node,int s,int e){
    if(s>e)return;
    if(s==e){
        seg1[node]=a[s];
        seg2[node]=b[s];
        return;
    }
    int mid=(s+e)>>1;
    build(2*node+1,s,mid);
    build(2*node+2,mid+1,e);
    seg1[node]=gcd(seg1[2*node+1],seg1[2*node+2]);
    seg2[node]=gcd(seg2[2*node+1],seg2[2*node+2]);
}
int query(vector<int>&seg,int node,int s,int e,int l,int r){
    if(r<s || l>e){
        return 0;
    }
    if(l<=s && r>=e){
        return seg[node];
    }
    int mid=(s+e)>>1;
    return gcd(query(seg,2*node+1,s,mid,l,r),query(seg,2*node+2,mid+1,e,l,r));
}
int find_a(int g,int idx=0){
    //if pre[0][i]<g -> pre[0][i+1]<g
    int l=-1;//always true;
    int r=n;// never true;
    if(pre[idx][0]%g!=0){
        return -1;
    }
    while(r-l>1){
        int mid=l+(r-l)/2;
        if(pre[idx][mid]%g==0){
            l=mid;
        }
        else{
            r=mid;
        }
    }
   // debug(l);
    return l;

}
int find_b(int g,int idx=0){
    int l=-1;//always <g
    int r=n;//>=g
    if(suf[idx][n-1]%g!=0){
        return n;
    }
    while(r-l>1){
        int mid=l+(r-l)/2;
        if(suf[idx][mid]%g==0){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    return r;
}
vector<int>hard_ans={36,2,3,36,1};
int search(vector<int>&seg,int l1,int g){
    //returns max idx>=l1 s.t. g(l1,idx)%g==0
    int l=l1-1;//always true
    int r=n;//always false
    while(r-l>1){
        int mid=l+(r-l)/2;
        if(query(seg,0,0,n-1,l1,mid)%g==0){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    return l;
}
int search1(vector<int>&seg,int r1,int g){
    //returns max idx>=l1 s.t. g(l1,idx)%g==0
    int l=-1;//always false
    int r=r1+1;//always true
    while(r-l>1){
        int mid=l+(r-l)/2;
        if(query(seg,0,0,n-1,mid,r1)%g==0){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    return r;
}
ll calc(int i,int g1,int g2){
        if(i>0 && pre[0][i-1]%g1!=0){
            return 0;
        }
        if(i>0 && pre[1][i-1]%g2!=0){
            return 0;
        }
         //dbgm(g1,g2);
        int r1=find_b(g1,0);
        int r2=find_b(g2,1);
        int l1=search(seg2,i,g1);
        int l2=search(seg1,i,g2);
         //dbgm(l1,l2);
        int l=min(l1,l2);
        int r=max(r1,r2);
        if(l<i){
            return 0;
        }
        r=max(r,i+1);
        ll ans1=max(0,(l-r+2));
        return ans1;
}
bool calcc(int i,int g1,int g2){
        if(i>0 && pre[0][i-1]%g1!=0){
            return 0;
        }
        if(i>0 && pre[1][i-1]%g2!=0){
            return 0;
        }
         //dbgm(g1,g2);
        int r1=find_b(g1,0);
        int r2=find_b(g2,1);
        int l1=search(seg2,i,g1);
        int l2=search(seg1,i,g2);
         //dbgm(l1,l2);
        int l=min(l1,l2);
        int r=max(r1,r2);
        return r<=l+1;
}
int calc1(){
    int ans=0;
    vector<int>gs1;
    for(int i=0;i<n;i++){
        gs1.pb(pre[0][i]);
        gs1.pb(pre[1][i]);
    }
    for(int i=n-1;i>=0;i--){
        gs1.pb(suf[0][i]);
        gs1.pb(suf[1][i]);
    }
    sort(all(gs1));gs1.erase(unique(all(gs1)),gs1.end());
    int n1=gs1.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n1;j++){
            int g1=gs1[j];
            for(int k=j+1;k<n1;k++){
                int g2=gs1[k];
                if(calcc(i,g1,g2) || calcc(i,g2,g1)){
                    ans=max(ans,g1+g2);
                }
            }
        }
    }
    ans=max(ans,pre[0][n-1]+pre[1][n-1]);
    return ans;
}
void solve(int t){
    cin>>n;
    a.clear();b.clear();seg1.clear();seg2.clear();
    seg1.resize(4*n,0),seg2.resize(4*n,0);
    a.resize(n);b.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    build(0,0,n-1);
    for(int i=0;i<2;i++){
        pre[i].clear();suf[i].clear();
        pre[i].resize(n+1,0);
        suf[i].resize(n+1,0);
    }
    int g1=0;
    int g2=0;
    for(int i=0;i<n;i++){
        pre[0][i]=g1=gcd(g1,a[i]);
        pre[1][i]=g2=gcd(g2,b[i]);

    }
    g1=0;g2=0;
    for(int i=n-1;i>=0;i--){
        suf[0][i]=g1=gcd(g1,a[i]);
        suf[1][i]=g2=gcd(g2,b[i]);
    }
    int ans=calc1();

   ll ct=0;
vector<int>gss;
for(int i=0;i<n;i++){
    gss.pb(pre[0][i]);
    gss.pb(suf[0][i]);
}
sort(all(gss));
gss.erase(unique(all(gss)),gss.end());
int n1=gss.size();
ll mxi=ans;
//dbg(gss);
for(int i=0;i<n;i++){
    //dbg(i);
    set<int>st;
    for(int j=0;j<n1;j++){
        g1=gss[j];
        g2=ans-g1;
        if(!st.count(g2)){
        if(g2<=0)continue;
        if(i>0 && pre[0][i-1]%g1!=0){
            continue;
        }
        if(i>0 && pre[1][i-1]%g2!=0){
            continue;
        }
        //dbgm(g1,g2);
        int r1=find_b(g1,0);
        int r2=find_b(g2,1);
        int l1=search(seg2,i,g1);
        int l2=search(seg1,i,g2);
        //dbgm(l1,l2);
        int l=min(l1,l2);
        int r=max(r1,r2);
        //dbgm(r1,r2);
        if(l>=i){
        r=max(r,i+1);
        ll ans1=max(0,(l-r+2));
        //dbg(ans1);
        ct+=ans1;
        st.insert(g2);
        }
        }
        if(!st.count(g1)){
            ll ans1=calc(i,g2,g1);
            ////dbg(ans1);
            ct+=ans1;
            if(ans1>0){
            st.insert(g1);
            }
        }

    }
}
cout<<ans<<" "<<ct<<"\n";




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
    solve(t);
  }
    
}