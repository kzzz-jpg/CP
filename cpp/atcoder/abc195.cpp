#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct bag{
        int w,v;
        bool vs;
        bool operator < (bag o)const{
                return v>o.v;
        }
} a[100];
struct bx{
        int sz,id;
        bool operator <(bx o) const{
                return sz<o.sz;
        }
} b[100];
signed main(){
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++){
                cin>>a[i].w>>a[i].v;
        }
        for(int i=1;i<=m;i++) cin>>b[i].sz,b[i].id=i;
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        while(q--){
                int ans=0,l,r;
                for(int i=1;i<=n;i++) a[i].vs=0;
                cin>>l>>r;
                for(int i=1;i<=m;i++){
                        if(b[i].id>=l&&b[i].id<=r) continue;
                        for(int j=1;j<=n;j++){
                                if(a[j].w<=b[i].sz&&!a[j].vs){
                                        ans+=a[j].v;
                                        a[j].vs=1;
                                        break;
                                }
                        }
                }
                cout<<ans<<'\n';
        }
}
