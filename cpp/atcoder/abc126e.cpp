#include<bits/stdc++.h>
using namespace std;
#define int long long
int fa[200500],sz[200500],lt;
int n,m;
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
        lt--;
}
signed main(){
        cin>>n>>m;
        lt=n*2;
        for(int i=1;i<=2*n;i++) fa[i]=i,sz[i]=1;
        int x,y,z;
        for(int i=1;i<=m;i++){
                cin>>x>>y>>z;
                if(z&1){
                        cb(x,y+n);
                        cb(x+n,y);
                }else{
                        cb(x,y);
                        cb(x+n,y+n);
                }
        }
        cout<<(lt>>1)<<'\n';
}
