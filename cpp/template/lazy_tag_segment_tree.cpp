#include<bits/stdc++.h>
using namespace std;
#define int long long
struct seg{
    int tr[200500*4],a[200500],ud[200500*4],ad[200500*4];
    void pull(int id){
        tr[id]=tr[id<<1]+tr[id<<1|1];
    }
    void push(int l,int r,int id){
        int mid = (l+r)>>1;
        if(ud[id]){
            if(l!=r){
                ud[id<<1]=ud[id];
                ad[id<<1]=0;
                tr[id<<1]=(mid-l+1)*ud[id];
                ud[id<<1|1]=ud[id];
                ad[id<<1|1]=0;
                tr[id << 1 | 1]=(r-mid)*ud[id];
            } 
            ud[id]=0;
        }
        if(ad[id]){
            if(l!=r){
                ad[id<<1]+=ad[id];
                tr[id<<1]+=(mid-l+1)*ad[id];
                ad[id<<1|1]+=ad[id];
                tr[id<<1|1]+=(r-mid)*ad[id];
            }
            ad[id]=0;
        }
    }
    void build(int l,int r,int id){
        if(l==r) {
			tr[id]=a[l];
			return;
		}
        int mid = (l+r)>>1;
        build(l,mid,id<<1);
        build(mid+1,r,id<<1|1);
        pull(id);
    }
    int query(int ql,int qr,int l,int r,int id){
        if(r<ql||qr<l) return 0;
        push(l,r,id);
        if(ql<=l&&r<=qr){
            return tr[id];
        }
        int mid = (l+r)>>1;
        return query(ql,qr,l,mid,id<<1)+query(ql,qr,mid+1,r,id<<1|1);
    }
    void modify_add(int ql,int qr,int v,int l,int r,int id){
        if(r<ql||qr<l){
            return;
        }
        push(l,r,id);
        if(ql<=l&&r<=qr){
            ad[id]=v;
            tr[id]+=(r-l+1)*v;
			return;
        }
        int mid=(l+r)>>1;
        modify_add(ql,qr,v,l,mid,id<<1);
        modify_add(ql,qr,v,mid+1,r,id<<1|1);
        pull(id);
    }
    void modify_update(int ql,int qr,int v,int l,int r,int id){
        if(r<ql||qr<l){
            return;
        }
        push(l,r,id);
        if(ql<=l&&r<=qr){
            ud[id]=v;
            ad[id]=0;
            tr[id]=(r-l+1)*v;
			return;
        }
        int mid=(l+r)>>1;
        modify_update(ql,qr,v,l,mid,id<<1);
        modify_update(ql,qr,v,mid+1,r,id<<1|1);
        pull(id);
    }
} st;
void solve(){
    int n,q;
    cin>>n>>q;
    int a,b,v,op;
    for(int i=1;i<=n;i++) cin>>st.a[i];
    st.build(1,n,1);
    while(q--){
        cin>>op;
        if(op==1){
            cin>>a>>b>>v;
            st.modify_add(a,b,v,1,n,1);
        }else if(op==2){
            cin>>a>>b>>v;
            st.modify_update(a,b,v,1,n,1);
        }else{
            cin>>a>>b;
            cout<<st.query(a,b,1,n,1)<<'\n';
        }
    }
}
signed main(){
    int t=1;
    while(t--){
        solve();
    }
}