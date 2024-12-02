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
int n,m;
vector<pii>aa;
vector<int>dd,kk,papa;
int root(int x){
    if(papa[x]==x){
        return x;
    }
    return (papa[x]=root(papa[x]));
}
void solve(int ii){
    cin>>n>>m;
    aa.clear();dd.clear();kk.clear();
    aa.resize(m+1);dd.resize(m+1),kk.resize(m+1);
    for(int i=1;i<=m;i++){
        cin>>aa[i].ff>>dd[i]>>kk[i];
        aa[i].ss=i;
    }
    papa.clear();
    papa.resize(n+1);
    for(int i=1;i<=n;i++){
        papa[i]=i;
    }
    sort(all(aa));
    int ans=0;
    vector<int>vv[2][11];
    vector<int>mina[2][11];
    vector<vector<int>>vv1;
    vector<int>arr[n+1];
    vv1.resize(n+1,vector<int>(11,-1));
    set<int>st;
      for(int i=0;i<11;i++){
        vv[0][i].resize(10,-1);
        vv[1][i].resize(10,-1);
        mina[0][i].resize(10,-1);
        mina[1][i].resize(10,-1);
    }
    for(int i=1;i<=m;){
        //   dbg(i);
            for(int j=0;j<=10;j++){
                vv[1][j]=vv[0][j];
                mina[1][j]=mina[0][j];
            }
            vector<int>tmp;
        int i1=i;
           bool f=false;
        while(i1<=m && aa[i1].ff==aa[i].ff){
          int d=dd[aa[i1].ss];
            arr[aa[i1].ff].pb(d);
        int k=kk[aa[i1].ss];
      //  dbgm(d,k);
        for(int j=aa[i1].ff;j<=min(aa[i1].ff+k*d,(aa[i1].ff+100));j+=d){
            for(int d1=1;d1<=10;d1++){
        //       dbg(vv[d1]);
                if(vv[0][d1][j%d1]>=j){
                    f=true;
                    tmp.pb(root(mina[0][d1][j%d1]));
                }
            }
        }
       //dbgm(d,k);
      // dbgm(aa[i1].ff%d,d);
        vv1[aa[i1].ff][d]=max(vv1[aa[i1].ff][d],aa[i1].ff+k*d);
        if(aa[i1].ff+k*d>vv[1][d][aa[i1].ff%d]){
             vv[1][d][aa[i1].ff%d]=aa[i1].ff+k*d;
             mina[1][d][aa[i1].ff%d]=root(aa[i1].ff);
        }
        i1++;
        }
     //    dbg(f);
        if(!f){
            st.insert(aa[i].ff);
       //     dbg(st);
        }
        else{
            // dbg(aa[i].ff);
            // dbg(tmp);
            int ss=-1;
            trav(z,tmp){
                if(st.count(z)){
                    st.erase(z);
                    if(ss==-1){
                        ss=z;
                    }
                    else{
                        papa[z]=ss;
                    }
                }

            }
            if(ss!=-1){
                papa[aa[i].ff]=ss;
            st.insert(ss);
            }
         //   dbg(st);
        }
        i=i1;
     //   dbg(i);
        for(int j=0;j<=10;j++){
                vv[0][j]=vv[1][j];
                mina[0][j]=mina[1][j];
              //  dbg(vv[0][j]);
        }
            
    }
    for(int i=0;i<11;i++){
        vv[0][i].clear();
        vv[0][i].resize(10,-1);
    }
    // debug(st);
    // dbg(vv1);
    for(int i=1;i<=n;i++){
       // dbg(i);
        if(!arr[i].empty()){
            trav(d,arr[i]){
              //  dbg(d);
               // dbg(vv1[i]);
            vv[0][d][i%d]=max(vv[0][d][i%d],vv1[i][d]);
            }
        }
        else{
          //  dbg(i);
            bool f=false;
                for(int d1=1;d1<=10;d1++){
            //   dbg(vv[d1]);
                if(vv[0][d1][i%d1]>=i){
                    f=true;
                    break;
                }
                }
         //       dbg(f);
                if(!f){
                    st.insert(i);
                }
        }
    }
//dbg(st);
    // if(ii==0){
    //     cout<<"# "<<n<<" "<<m<<endl;
    //     for(int i=1;i<=m;i++){
    //         cout<<aa[i].ff<<" "<<dd[aa[i].ss]<<" "<<kk[aa[i].ss]<<endl;
    //     }
    // }
    // if(ii>4){
    //     return;
    // }
//    debug(st);
    cout<<st.size()<<endl;
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
  int ii=0;
  while(ii<t){
    solve(ii);
    ii++;
  }
    
}