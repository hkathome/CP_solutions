#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,k;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());

    cin>>k;
    while(k--){
        int l1,r1;
        cin>>l1>>r1;
    int l=-1;
    int r=n;
    while(l+1<r){
        int mid=l+(r-l)/2;
        if(a[mid]<l1){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cerr<<l<<" ";
    int l11=r;
     l=-1;
     r=n;
    while(l+1<r){
        int mid=l+(r-l)/2;
        if(a[mid]<=r1){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cerr<<l<<'\n';
    cout<<r-l11<<"\n";
    }
}
