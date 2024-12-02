#include <bits/stdc++.h>
#include <set>
#define ll long long 
#define pb push_back
#define pii pair<int,int>
#define debug(x) cerr<<#x<<" "<<x<<"\n";
#include <chrono>
#include <random>
using namespace std;
const int mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int expo(int a,int b){
    if(b==0)return 1;
    ll z=expo(a,b/2);
    z*=z;
    z%=mod;
    if(b&1){
        z*=1ll*a;
        z%=mod;
    }
    return z;
}
 

void solve(){
    
    int n;
    cin>>n;
    vector<int>a(n+1),pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;

    }
    if(n<2){
        cout<<"Impossible\n";
        return;
    }
    if(n==2){
        if(a[1]==2){
            cout<<"Impossible\n";
        }
        else{
            cout<<"Possible\n";
            cout<<"2 1\n";
            cout<<"2 1\n";
        }
        return;

    }
    vector<int>q1;
    for(int i=1;i<=n;i++){
        q1.pb(i);
    }
      vector<int>p_ans,q_ans;
    auto getPermutation=[&](){
    shuffle(q1.begin(),q1.end(),rng);

    return q1;
    
};
   if(n<6){
    vector<int>perm;
    for(int i=1;i<=n;i++){
        perm.pb(i);
    }
    do{
        vector<int>q(n+1);
        bool f1=true;
        for(int i=1;i<=n;i++){
            q[i]=perm[i-1];
            if(q[i]==i){
                f1=false;
                break;
            }

        }
        if(!f1)continue;

        vector<int>p(n+1);
        for(int i=1;i<=n;i++){
            p[q[i]]=pos[i];
            if(q[i]==pos[i]){
                f1=false;
                break;
            }
        }
        if(f1){
            p_ans=p;
            q_ans=q;
            break;
        }
    }while(next_permutation(perm.begin(),perm.end()));
   // assert(p_ans.size()==(n+1));
   }
   else{
    int moves=0;
    bool f=false;
    while(!f){
        getPermutation();
        vector<int>q(n+1);
        vector<int>p(n+1);
        // for(int i=1;i<=n;i++){
        //     debug(q[i]);
        // }
        bool f1=true;
        for(int i=1;i<=n;i++){
            //p[q[i]]=pos[i]
            q[i]=q1[i-1];
            if(q[i]==i){
                f1=false;
                break;
            }
            p[q[i]]=pos[i];
            if(q[i]==pos[i]){
                f1=false;
                break;
            }
        }
        f=f1;
        if(f){
            p_ans=p;
            q_ans=q;
            break;
        }
    moves++;
    }
    
   }
   if(p_ans.size()<=n){
    cout<<"Impossible\n";
    return;
   }
 
    cout<<"Possible\n";
    for(int i=1;i<=n;i++){
        cout<<p_ans[i]<<" ";
    }
    cout<<"\n";
    for(int i=1;i<=n;i++){
        cout<<q_ans[i]<<" ";
    }
    cout<<"\n";
    
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
    int t;
    cin>>t;
    while(t--){
    solve();
    }
   
    
}