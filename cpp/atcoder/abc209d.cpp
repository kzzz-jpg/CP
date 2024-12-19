#include<bits/stdc++.h>
using namespace std;
const int N=200500;
int n,q;
int hd[N],to[N],nxt[N],bz[26][N],dpt[N];
int lncnt=1;
int cnt=1;
void addE(int a,int b){
        nxt[cnt]=hd[a];
        to[cnt]=b;
        hd[a]=cnt++;
}
void dfs(int x,int par,int dp){
        dpt[x]=dp;
        bz[0][x]=par;
        for(int e=hd[x];e;e=nxt[e]) if(to[e]!=par) dfs(to[e],x,dp+1);
}
void init(){
        for(int i=1;i<26;i++){
                for(int j=1;j<=n;j++) bz[i][j]=bz[i-1][bz[i-1][j]];
        }
}
int lca(int a,int b){
        if(dpt[a]<dpt[b]) swap(a,b);
        for(int i=25;i>=0;i--){
                while(dpt[bz[i][a]]>dpt[b]) a=bz[i][a];
        }
        a=bz[0][a];
        if(a==b) return a;
        for(int i=25;i>=0;i--){
                while(bz[i][a]!=bz[i][b]) a=bz[i][a],b=bz[i][b];
        }
        return bz[0][a];
}
int ans;
signed main(){
        ios_base::sync_with_stdio(0),cin.tie(0);
        cin>>n>>q;
        int x,y;
        for(int i=1;i<n;i++){
                cin>>x>>y;
                addE(x,y),addE(y,x);
        }
        dfs(1,1,1);
        init();
        while(q--){
                cin>>x>>y;
                ans=dpt[x]+dpt[y]-2*dpt[lca(x,y)];
                if(ans&1) cout<<"Road\n";
                else cout<<"Town\n";
        }
}
