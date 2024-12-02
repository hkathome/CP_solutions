#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
using namespace std;
const int mod=998244353;

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
int addEdge(int x){
    cout<<"+ "<<x<<endl;
    cout.flush();
    int r;
    cin>>r;
    cout.flush();
    return r;
}
int ask(int i,int j){
    cout<<"? ";
    cout<<i<<" "<<j<<endl;
    cout.flush();
    int r;
    cin>>r;
    cout.flush();
    return r;
}
void printArray(vector<int>&ans){
    for(auto &z:ans){
        cout<<z<<" ";
    }
    cout.flush();
}
void solve(){
  int n;
  cin>>n;
  int p=1;//a random node p1
  int r=addEdge(n+1);//would add [1,2,...]->[n,n-1,n-2,...]
  assert(r!=-1);
  r=addEdge(n+2);//would add [2,3,...]->[n,n-1,n-2,...]
  //1->n->2->n-1->3->n-2->...
  assert(r!=-1);
  vector<int>dis(n+1,-1);
  for(int i=2;i<=n;i++){
    dis[i]=ask(p,i);
  }
  //n+1 queries done
  int id=-1;
  int d=-1;
  for(int i=2;i<=n;i++){
    if(dis[i]>d){
        d=dis[i];
        id=i;
    }
  }
  vector<int>disf(n+1,-1);
  disf[d]=1;
  disf[0]=id;
  for(int i=2;i<=n;i++){
    if(i!=id){
        int x=ask(id,i);
        assert(disf[x]==-1);
        disf[x]=i;
    }
  }
  
  vector<int>ans(n);
  int l=1;
  r=n;
  
  for(int i=0;i<n;i++){
    assert(disf[i]!=-1);
    if(i&1){
        ans[disf[i]-1]=r;
        r--;
    }
    else{
        ans[disf[i]-1]=l;
        l++;
    }
  }
  cout<<"! ";
  cout.flush();
printArray(ans);
vector<int>dif1(n,-1);
id=disf[n-1];
dif1[0]=id;
ans.clear();
ans.resize(n);
for(int i=1;i<n;i++){
    dif1[i]=disf[n-1-i];
}
 l=1;
  r=n;
  
  for(int i=0;i<n;i++){
    assert(dif1[i]!=-1);
    if(i&1){
        ans[dif1[i]-1]=r;
        r--;
    }
    else{
        ans[dif1[i]-1]=l;
        l++;
    }
  }
printArray(ans);
int res;
cin>>res;
cout.flush();
if(res==1){
    return;
}
exit(0);

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
         solve();
    }
   
    
}