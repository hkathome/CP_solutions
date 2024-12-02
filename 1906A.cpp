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
int dir[][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
bool ok(int x,int y){
    if(x<0 || x>2 || y<0 || y>2){
        return false;
    }
    return true;
}
void solve(){
    string s[3];
    cin>>s[0];
    cin>>s[1];
    cin>>s[2];
    // vector<pii>posA;
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         if(s[i][j]=='A'){
    //             posA.pb({i,j});
    //         }
    //     }
    // }
    // char A='A';
    // if(posA.empty()){
    //       for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         if(s[i][j]=='B'){
    //             posA.pb({i,j});
    //         }
    //     }
    // }
    // A='B';
    // }
    // if(posA.empty()){
    //     cout<<"CCC\n";
    //     return;
    // }
    auto possible=[&](int a,int b){
        int pos_x1=a/3;
        int pos_y1=a%3;
        int pos_x2=b/3;
        int pos_y2=b%3;
        for(int i=0;i<8;i++){
             int pos_x=pos_x1+dir[i][0];
            int pos_y=pos_y1+dir[i][1];
            if(pos_x==pos_x2 && pos_y==pos_y2){
                return true;
            }
        }
        return false;
    };
    // trav(z,posA){
    //     char c='W';
    //     vector<pii> pos1;
    //     pos1.pb({-1,-1});
    //     for(int i=0;i<8;i++){
    //         int pos_x=z.ff+dir[i][0];
    //         int pos_y=z.ss+dir[i][1];
    //         if(ok(pos_x,pos_y)){
    //             if(s[pos_x][pos_y]<c){
    //                 c=s[pos_x][pos_y];
    //                 pos1[0]={pos_x,pos_y};
    //             }
    //         }
    //     }
       

    //     if(c!='W'){
    //         pos1.pop_back();
    //          for(int i=0;i<8;i++){
    //         int pos_x=z.ff+dir[i][0];
    //         int pos_y=z.ss+dir[i][1];
    //         if(ok(pos_x,pos_y)){
    //             if(s[pos_x][pos_y]==c){
    //                 pos1.pb({pos_x,pos_y});
    //             }
    //         }
    //          }
    //         char t='W';
    //         trav(z1,pos1){
    //          for(int i=0;i<8;i++){
    //         int pos_x=z1.ff+dir[i][0];
    //         int pos_y=z1.ss+dir[i][1];
    //         // debug2(pos_x,pos_y);
    //         if(ok(pos_x,pos_y)){
    //             if(pos_x==z.ff && pos_y==z.ss){
    //                 continue;
    //             }
    //             if(s[pos_x][pos_y]<t){
    //                 t=s[pos_x][pos_y];
    //             }
    //         }
    //           }
    //         if(t!='W'){
    //             string s1="";
    //             s1+=A;
    //             s1+=c;
    //             s1+=t;
    //             ss.pb(s1);
    //         }
    //     }
    //     }
    // }
    // debug(ss);
     vector<string>ss;
     for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(i==j){
                continue;
            }
            for(int k=0;k<9;k++){
                if(i==k || j==k){
                    continue;
                }
                if(possible(i,j) && possible(j,k)){
                    string ss1="";
                    ss1+=s[i/3][i%3];
                    ss1+=s[j/3][j%3];
                    ss1+=s[k/3][k%3];
                    ss.pb(ss1);
                }
            }
        }
     }
    sort(all(ss));
    cout<<ss[0]<<"\n";
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
 // cin>>t;
  while(t--){
    solve();
  }
    
}