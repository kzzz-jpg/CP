#include<bits/stdc++.h>
using namespace std;
int fa[400500],sz[400500],pt[400500];
int find(int x){
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
}
void cb(int a,int b){
        a=find(a),b=find(b);
        if(a==b)return;
        if(sz[a]>sz[b]) swap(a,b);
        fa[a]=b;
        sz[b]+=sz[a];
        pt[b]+=pt[a];
}
int n,m;
signed main(){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
                fa[i]=i;sz[i]=1;pt[i+n]=1;
                fa[i+n]=i+n,sz[i+n]=1;
        }
        int x,y;
        for(int i=1;i<=m;i++){
                cin>>x>>y;
                cb(x,y+n);
                cb(x+n,y);
        }
        for(int i=1;i<=n;i++){
                if(find(i)==find(i+n)){
                        cout<<0<<'\n';
                        return 0;
                }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
                cerr<<(n-pt[find(i+n)]-1)<<'\n';
                ans+=(n-pt[find(i+n)]-1);
        }
        cout<<ans/2<<'\n';
}
