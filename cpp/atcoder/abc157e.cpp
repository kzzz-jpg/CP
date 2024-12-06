#include<bits/stdc++.h>
using namespace std;
int n,q;
string s;
int a[500500];
int tr[2000500];
void build(int l,int r,int id){
        if(l==r){
                tr[id]=a[l];
                return;
        }
        int mid=l+r>>1;
        build(l,mid,id<<1);
        build(mid+1,r,id<<1|1);
        tr[id]=tr[id<<1]|tr[id<<1|1];
}
int query(int l,int r,int L,int R,int id){
        if(L>r||R<l) return 0;
        if(L<=l&&r<=R) return tr[id];
        int mid=l+r>>1;
        return query(l,mid,L,R,id<<1)|query(mid+1,r,L,R,id<<1|1);
}
void modify(int l,int r,int pos,int v,int id){
        if(l==r){
                tr[id]=v;
                return;
        }
        int mid=l+r>>1;
        if(pos<=mid) modify(l,mid,pos,v,id<<1);
        else modify(mid+1,r,pos,v,id<<1|1);
        tr[id]=tr[id<<1]|tr[id<<1|1];
}
signed main(){
        cin>>n>>s>>q;
        for(int i=1;i<=n;i++){
                a[i]=1<<(s[i-1]-'a');
        }
        build(1,n,1);
        int op,x,y;
        char c;
        while(q--){
                cin>>op;
                if(op==1){
                        cin>>x>>c;
                        y=1<<(c-'a');
                        modify(1,n,x,y,1);
                }else{
                        cin>>x>>y;
                        int res=query(1,n,x,y,1);
                        cout<<__builtin_popcount(res)<<'\n';
                }
        }
}
