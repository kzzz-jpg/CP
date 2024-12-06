#include<bits/stdc++.h>
using namespace std;
int h,w,n;
struct qry{
        int l,r,h,id;
        bool operator < (qry o)const{
                return h>o.h;
        }
} a[200500];
int tr[800500],lz[800500];
void push(int l,int r,int id){
        if(l==r) return;
        if(lz[id]==0) return;
        lz[id<<1]=lz[id<<1|1]=tr[id<<1]=tr[id<<1|1]=lz[id];
        lz[id]=0;
}
void build(int l,int r,int id){
        if(l==r){
                tr[id]=h;
                return;
        }
        int mid=l+r>>1;
        build(l,mid,id<<1);
        build(mid+1,r,id<<1|1);
        tr[id]=min(tr[id<<1],tr[id<<1|1]);
}
int query(int l,int r,int L,int R,int id){
        if(L>r||R<l) return 1e9;
        push(l,r,id);
        if(L<=l&&r<=R) {
                return tr[id];
        }
        int mid=l+r>>1;
        return min(query(l,mid,L,R,id<<1),query(mid+1,r,L,R,id<<1|1));
}
void modify(int l,int r,int L,int R,int v,int id){
        if(L>r||R<l) return;
        push(l,r,id);
        if(L<=l&&r<=R){
                tr[id]=v;
                lz[id]=v;
                return;
        }
        int mid=l+r>>1;
        modify(l,mid,L,R,v,id<<1);
        modify(mid+1,r,L,R,v,id<<1|1);
        tr[id]=min(tr[id<<1],tr[id<<1|1]);
}
int ans[200500];
signed main(){
        cin>>h>>w>>n;
        build(1,w,1);
        //for(int i=1;i<=15;i++) cerr<<query(1,n,i,i,1)<<' ';
        //cerr<<'\n';
        for(int i=1;i<=n;i++){
                cin>>a[i].h>>a[i].l>>a[i].r;
                a[i].r+=a[i].l-1;
                a[i].id=i;
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
                ans[a[i].id]=query(1,w,a[i].l,a[i].r,1);
                modify(1,w,a[i].l,a[i].r,ans[a[i].id]-1,1);
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<'\n';
}
