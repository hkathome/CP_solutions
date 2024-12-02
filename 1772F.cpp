#include <bits/stdc++.h>
#include <set>
#define ll long long 
#define pb push_back
#define pii pair<int,int>
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
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    
    vector<vector<vector<int>>>mats(k+1,vector<vector<int>>(n,vector<int>(m)));
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            for(int l=0;l<m;l++){
                char w;
                cin>>w;
                mats[i][j][l]=w-'0';
            }
        }
    }
    if(k==0){
        cout<<1<<"\n"<<"0\n";
        return;
    }
    // for(int i=0;i<=k;i++){
    //     for(int j=0;j<n;j++){
    //         for(int l=0;l<m;l++){
    //             cerr<<mats[i][j][l]<<" ";
    //         }
    //     }
    // }
    cerr<<n<<" "<<m<<" "<<k<<"\n";
    vector<vector<int>>mat1;
    auto poss=[&](int idxp,int idxi,int idxj){
        if(idxi==0 || idxi==(n-1) || idxj==0 || idxj==(m-1)){
            return false;
        }
        int c0=mats[idxp][idxi][idxj];
        int c1=mat1[idxi-1][idxj];
        int c2=mats[idxp][idxi+1][idxj];
        int c3=mat1[idxi][idxj-1];
        int c4=mats[idxp][idxi][idxj+1];
        if(c1==c2 && c2==c3 && c3==c4 && c4!=c0){
            return true;
        }
        return false;
    };
    for(int idx=0;idx<=k;idx++){
        //mat[idx] is starting seq;
         bool f=true;
         
         vector<vector<pii>>allmoves(k+1);
        for(int idx1=0;idx1<=k && f;idx1++){
            if(idx1==idx){
                continue;
            }
           
            vector<pii>moves;
            mat1.clear();
            mat1.resize(n,vector<int>(m));
            for(int i=0;i<n && f;i++){
                for(int j=0;j<m && f;j++){
                    mat1[i][j]=mats[idx1][i][j];
                    if(mat1[i][j]!=mats[idx][i][j]){
                        // cerr<<idx1<<" "<<idx<<endl;
                        // cerr<<i<<" "<<j<<endl;
                        if(poss(idx,i,j)){
                            moves.pb({i,j});
                        }
                        else{
                            f=false;
                            break;
                        }
                    }
                }
            }
            cerr<<f<<"\n";
            if(!f){
                break;
            }
            allmoves[idx1]=moves;

        }
        
        if(!f){continue;}
        vector<pii>len;
        for(int idx1=0;idx1<=k;idx1++){
            if(idx1==idx){
                continue;
            }
            len.pb({allmoves[idx1].size(),idx1});
         }
         
        sort(len.begin(),len.end());
        for(int i=0;i<(len.size())-1 && f;i++){
            vector<pii>moves=allmoves[len[i].second];
            vector<pii>nt=allmoves[len[i+1].second];
            set<pii>next(nt.begin(),nt.end());
            for(int j=0;j<moves.size();j++){
                if(!next.count(moves[j])){
                    f=false;
                    break;
                }
            }
        }
        if(!f){
            continue;
        }
        if(f){
            cout<<idx+1<<"\n";
            //getting answer 
            set<pii>pres;
            vector<pii>ans;
              for(int i=0;i<len.size()-1;i++){
                vector<pii>moves=allmoves[len[i].second];
                vector<pii>next=allmoves[len[i+1].second];
                for(int j=0;j<moves.size();j++){
                   if(!pres.count(moves[j])){
                    ans.pb({moves[j].first+1,moves[j].second+1});
                    pres.insert(moves[j]);
                   }
                }
                ans.pb({-2,len[i].second+1});
              }

              vector<pii>moves=allmoves[len.back().second];
                  for(int j=0;j<moves.size();j++){
                   if(!pres.count(moves[j])){
                    ans.pb({moves[j].first+1,moves[j].second+1});
                    pres.insert(moves[j]);
                   }
                   
                }
               ans.pb({-2,len.back().second+1});
               cout<<ans.size()<<"\n";
                for(auto &z:ans){
                    if(z.first==-2){
                        cout<<2<<" "<<z.second<<"\n";
                    }
                    else{
                        cout<<1<<" "<<z.first<<" "<<z.second<<"\n";
                    }
                }
            return;
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
    solve();
   
    
}