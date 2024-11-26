#include<bits/stdc++.h>
using namespace std;
int n,q;
int fa[500500],sz[500500],c[500500],cnt[500500],l[500500],r[500500];
int find(int x){
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
}
void cb(int a,int b){
        a=find(a),b=find(b);
        if(a==b) return;
        if(sz[a]>sz[b]) swap(a,b);
        fa[a]=b;
        l[b]=min(l[a],l[b]);
        r[b]=max(r[a],r[b]);
        sz[b]+=sz[a];
}
signed main(){
        cin>>n>>q;
        for(int i=1;i<=n;i++) sz[i]=1,fa[i]=i,c[i]=i,cnt[i]=1,l[i]=i,r[i]=i;
        int op,x,y;
        while(q--){
                cin>>op;
                if(op==1){
                        cin>>x>>y;
                        x=find(x);
                        cnt[c[x]]-=sz[x];
                        c[x]=y;
                        cnt[y]+=sz[x];
                        if(c[find(l[x]-1)]==c[x]) cb(l[x]-1,x);
                        if(c[find(r[x]+1)]==c[x]) cb(x,r[x]+1);
                }else{
                        cin>>x;
                        /*
                        cerr<<"============================\n";
                        for(int i=1;i<=n;i++) cerr<<c[find(i)]<<' ';
                        cerr<<'\n';
                        for(int i=1;i<=n;i++) cerr<<cnt[i]<<' ';
                        cerr<<'\n';
                        cerr<<'\n'<<"=========================\n";
                        */
                        cout<<cnt[x]<<'\n';
                }
        }
}
