#include<bits/stdc++.h>
using namespace std;
int fa[200500],sz[200500];
int hd[200500],nxt[400500],to[400500];
int cnt=1;
void addE(int a,int b){
        nxt[cnt]=hd[a];
        to[cnt]=b;
        hd[a]=cnt++;
}
int find(int x){
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
}
void cb(int a,int b){
        a=find(a),b=find(b);
        if(a==b) return;
        if(sz[a]>sz[b]) swap(a,b);
        fa[a]=b;
        sz[b]+=sz[a];
}
int n,m,k;
signed main(){
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
        int x,y;
        for(int i=1;i<=m;i++){
                cin>>x>>y;
                cb(x,y);
                addE(x,y);
                addE(y,x);
        }
        for(int i=1;i<=k;i++){
                cin>>x>>y;
                addE(x,y);
                addE(y,x);
        }
        for(int i=1;i<=n;i++){
                int ans=sz[find(i)]-1;
                for(int e=hd[i];e;e=nxt[e]){
                        if(find(to[e])==find(i)) ans--;
                }
                cout<<ans<<'\n';
        }
}
