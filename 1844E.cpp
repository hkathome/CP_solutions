#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<int,int> > vpii;
#define mp make_pair
#define pb push_back

vpii adjList[4000];
int colour[4000],bad = 0;
int doDFS(int u,int c) {
    if (colour[u] != -1) {
        if (colour[u] != c) bad = 1;
        return 0;
    }
    colour[u] = c;
    for (auto [v,e]: adjList[u]) doDFS(v,c^e);
    return 0;
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
    int i;
    int t,n,m,k;
    int x1,y1,x2,y2;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&n,&m,&k);
        for (i = 0; i < k; i++) {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            x1--,y1--,x2--,y2--;
            adjList[min(x1,x2)].pb(mp(n+min(y1,y2),(x1+y1 != x2+y2)));
            adjList[n+min(y1,y2)].pb(mp(min(x1,x2),(x1+y1 != x2+y2)));
        }

        fill(colour,colour+n+m,-1),bad = 0;
        for (i = 0; i < n+m; i++) {
            if (colour[i] == -1) doDFS(i,0);
        }
        printf(bad ? "NO\n":"YES\n");

        for (i = 0; i < n+m; i++) adjList[i].clear();
    }
    return 0;
}
