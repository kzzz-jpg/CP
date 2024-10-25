#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1050][1050];
int n,q;
struct St{
    int tr[5050];
    int v[1050];
    void build(int l,int r,int id){
        if(l==r){
            tr[id]=v[l];
            return;
        }
        int mid=(l+r)>>1;
        build(l,mid,id<<1);
        build(mid+1,r,id<<1|1);
        tr[id]=tr[id<<1]+tr[id<<1|1];
    }
    St(){}
    St(St l,St r){
        for(int i=0;i<5050;i++){
            tr[i]=l.tr[i]+r.tr[i];
        }
    }
    St(int V[]){
        for(int i=0;i<=n;i++){
            v[i]=V[i];
        }
        build(1,n,1);
    }
    void modify(int l,int r,int x,int v,int id){
        if(x<l||x>r) return;
        if(l==r){
            tr[id]=v;
            return;
        }
        int mid=(l+r)>>1;
        modify(l,mid,x,v,id<<1);
        modify(mid+1,r,x,v,id<<1|1);
        tr[id]=tr[id<<1]+tr[id<<1|1];
    }
    int query(int l,int r,int L,int R,int id){
        if(R<l||L>r)return 0;
        if(L<=l&&r<=R) return tr[id];
        int mid=(l+r)>>1;
        return query(l,mid,L,R,id<<1)+query(mid+1,r,L,R,id<<1|1);
    }
} st[5050];
void build(int l,int r,int id){
    if(l==r){
        st[id]=St(a[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    st[id]=St(st[id<<1],st[id<<1|1]);
}
void modify(int l,int r,int x,int y,int v,int id){
    if(x<l||x>r)return;
    if(l==r){
        st[id].modify(1,n,y,v,1);
        return;
    }
    int mid=(l+r)>>1;
    modify(l,mid,x,y,v,id<<1);
    modify(mid+1,r,x,y,v,id<<1|1);
    st[id].modify(1,n,y,st[id<<1].query(1,n,y,y,1)+st[id<<1|1].query(1,n,y,y,1),1);
}
int query(int l,int r,int L,int R,int ll,int rr,int id){
    if(L>r||R<l) return 0;
    if(L<=l&&r<=R) return st[id].query(1,n,ll,rr,1);
    int mid=(l+r)>>1;
    return query(l,mid,L,R,ll,rr,id<<1)+query(mid+1,r,L,R,ll,rr,id<<1|1);
}
int op,x,y,xx,yy;
int32_t main(){
    cin>>n>>q;
    char c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c;
            if(c=='*') a[i][j]=1;
            else a[i][j]=0;
        }
    }
    build(1,n,1);
    while(q--){
        cin>>op;
        if(op==1){
            cin>>x>>y;
            modify(1,n,x,y,a[x][y]^=1,1);
        }else{
            cin>>x>>y>>xx>>yy;
            cout<<query(1,n,x,xx,y,yy,1)<<'\n';
        }
    }
}