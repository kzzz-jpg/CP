#include<bits/stdc++.h>
#define int long long
using namespace std;
struct rd{
        int x,y,v;
        rd(int xx,int yy,int vv):x(xx),y(yy),v(vv){}
        bool operator<(rd o)const{
                return v<o.v;
        }
};
int n,q,ans,lt;
int fa[200500],sz[200500];
int find(int x){
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
}
void cb(int a,int b){
        a=find(a),b=find(b);
        if(a==b) return;
        if(sz[a]>sz[b]) swap(a,b);
        fa[a]=b;
        sz[b]+=a;
        lt--;
}
signed main(){
        cin>>n>>q;
        lt=n;
        vector<rd> road;
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
        int k,c,x,y;
        while(q--){
                cin>>k>>c;
                cin>>x;
                for(int i=1;i<k;i++) cin>>y,road.emplace_back(x,y,c);
        }
        sort(road.begin(),road.end());
        for(auto x:road){
                if(find(x.x)==find(x.y)) continue;
                ans+=x.v;
                cb(x.x,x.y);
        }
        if(lt>1) cout<<-1<<'\n';
        else cout<<ans<<'\n';
}
