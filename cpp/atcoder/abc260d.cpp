#include<bits/stdc++.h>
using namespace std;
int fa[200500],sz[200500],ans[200500];
int find(int x){
        if(x==fa[x]) return x;
        return fa[x]=find(fa[x]);
}
void cb(int a,int b){
        a=find(a),b=find(b);
        if(a==b) return;
        if(sz[a]>sz[b]) swap(a,b);
        fa[a]=b;
        sz[b]+=a;
}
int n,k;
int p[200500];
signed main(){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
                cin>>p[i];
                fa[i]=i,sz[i]=1,ans[i]=-1;
        }
        set<pair<int,int>> s;
        for(int i=1;i<=n;i++){
                auto it=s.lower_bound({p[i],-1});
                if(it==s.end()) {
                        if(k>1)
                        s.insert({p[i],1});
                        else ans[find(p[i])]=i;
                }else{
                        int cnt=it->second+1;
                        cb(it->first,p[i]);
                        s.erase(it);
                        if(k>cnt)
                        s.insert({p[i],cnt});
                        else{
                                ans[find(p[i])]=i;
                        }
                }
        }
        for(int i=1;i<=n;i++){
                cout<<ans[find(i)]<<'\n';
        }
}
