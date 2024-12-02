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

const int N=2e5+100;// no. of values
const int M=30;//log(N)
struct node{
    node *l,*r;
    ll val;
}pool[N*M],*cur=pool,*rt[N];// we reserve N*30 nodes in beginning;

node* newnode(){
    return cur++;
}
int n;
vector<int>arr;
node* build(int tl,int tr){
    node* p=newnode();
    if(tl==tr){
        return p;
    }
    else{
        int mid=(tl+tr)>>1;
        p->l=build(tl,mid);
        p->r=build(mid+1,tr);
    }
    return p;
}
node* update(node* p,int tl,int tr,int pos,int x){
    node *q=newnode();
    *q=*p;//copying the values in p to q,but q is different from p
    //if we use q=p, then q will start pointing to memory pointed by p;
    q->val+=x;
    if(tl!=tr){
        int mid=(tl+tr)>>1;
        if(pos<=mid){
            q->l=update(p->l,tl,mid,pos,x);
        }
        else{
            q->r=update(p->r,mid+1,tr,pos,x);
        }
    }
    return q;
}
ll query(node *p,int tl,int tr,int l,int r){
    // debug2(tl,tr);
    // debug2(l,r);
    if(l>r)return 0;
    if(r<tl || l>tr)return 0;
    if(l<=tl && tr<=r) return p->val;
    else{
        int md=(tl+tr)>>1;
        // 	if (r<=md) return query(p->l,tl,md,l,r);
		// else if (l>md) return query(p->r,md+1,tr,l,r);
        return query(p->l,tl,md,l,r)+query(p->r,md+1,tr,l,r);
    }
}
ll query(int x,int l,int r){
    if(x==0){
        return 0;
    }
    assert(x<=n);
    assert(x>=0);
    //retrieve no of values in range [l,r] in prefix([1,x]) of given array
    ll ans= query(rt[x],1,n,l,r);
    return ans;
}
map<int,int>Mp;
void Persistence(vector<int>&v){
    arr.clear();//1-indexing for v

    for(int i=1;i<=n;i++){
        arr.pb(v[i]);
    }
    rt[0]=build(1,n);// range of values;
    sort(all(arr));
    arr.erase(unique(all(arr)),arr.end());
    int n1=arr.size();
    Mp.clear();
    for(int i=0;i<n1;i++){
        Mp[arr[i]]=i+1;
    }
    for(int i=1;i<=n;i++){
        rt[i]=update(rt[i-1],1,n,Mp[v[i]],v[i]);
    }
}
void solve(){
    cin>>n;
    vector<int>v(n+1);
    int mxi=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        mxi=max(mxi,v[i]);
    }
    Persistence(v);
    int q;
    cin>>q;
    ll ans=0;
    while(q--){
        ll l,r, x;
        cin>>l>>r>>x;
        l^=ans;
        r^=ans;x^=ans;
        auto it=upper_bound(all(arr),x);
        if(it==arr.begin()){
            ans=0;
            cout<<ans<<"\n";
            continue;
        }
        it--;
        ans=query(r,1,Mp[*it])-query(l-1,1,Mp[*it]);
        
        cout<<ans<<"\n";
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