#include <bits/stdc++.h>
#include <set>
#include <map>
#define ull unsigned long long 
#define lld long double
#define ll long long 
#define pb push_back
#define pii pair<int,int>
#define deb(x) cerr<<#x<<" "<<x<<"\n";
#define debug2(x,y) cerr<<#x<<" "<<x<<" "<<#y<<" "<<y<<"\n";
#define trav(z,x) for(auto &z:x)
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
const int inf=1e9+10;

//unordered_map<lli,lli,custom_hash> ed;
//unordered_map<lli,lli,custom_hash> mp;
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
vector<int>papa;
int root(int x){
  if(papa[x]==x){
    return x;
  }
  return papa[x]=root(papa[x]);
}

#define sv(a) sort(a.begin(),a.end())
#define sa(a,n) sort(a,a+n)
#define mp(a,b) make_pair(a,b)
#define vf first
#define vs second
#define all(x) x.begin(),x.end()
 
void solve(){
	int n , m , q;
	cin >> n >> m >> q;
	string st;
	cin >> st;
	vector<pair<int,int>> ranges;
	for(int i = 0; i < m; i++){
		int l , r;
		cin >> l >> r;
		l--;
		r--;
		ranges.pb(mp(l,r));
	}
	set<int> s;
	for(int i = 0; i < n; i++)s.insert(i);
	vector<int> v;
	int pos_in_v[n];
	memset(pos_in_v,-1,sizeof pos_in_v);
	for(int i = 0; i < m; i++){
		auto it = s.lower_bound(ranges[i].vf);
		vector<int> toerase;
		while(it != s.end() && (*it) <= ranges[i].vs){
			toerase.pb((*it));
			v.pb(toerase.back());
			pos_in_v[toerase.back()] = v.size()-1;
			it++;
		}
		while(toerase.size()){
			s.erase(toerase.back());
			toerase.pop_back();
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(st[i] == '1')cnt++;
	}
	int ans = 0;
	for(int i = 0; i < min(cnt , (int)v.size()); i++){
		if(st[v[i]] == '0')ans++;
	}
	
	while(q--){
		int pos;
		cin >> pos;
		pos--;
		if(pos_in_v[pos] != -1 && pos_in_v[pos] < cnt){
			if(st[pos] == '0'){
				ans--;
			}
			else ans++;
		}
		if(st[pos] == '0'){
			st[pos] = '1';
			cnt++;
			if(cnt <= v.size() && st[v[cnt-1]] == '0')ans++;
		}
		else {
			st[pos] = '0';
			if(cnt > 0 && cnt <= v.size() && st[v[cnt-1]] == '0')ans--;
			cnt--;
		}
		cout << ans << '\n';
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
 // cin>>t;
  while(t--){
    solve();
  }
    
}