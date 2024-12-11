#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200500],v[200500];
int tr[800500];
int gcd(int a,int b){
        if(a==0) return b;
        if(b==0) return a;
        return __gcd(a,b);
}
void build(int l,int r,int id){
        if(l==r) {
                tr[id]=v[l];
                return;
        }
        int mid=l+r>>1;
        build(l,mid,id<<1);
        build(mid+1,r,id<<1|1);
        tr[id]=gcd(tr[id<<1],tr[id<<1|1]);
}
int query(int l,int r,int L,int R,int id){
        if(L>r||R<l) return 0;
        if(L<=l&&r<=R) return tr[id];
        int mid=l+r>>1;
        return gcd(query(l,mid,L,R,id<<1),query(mid+1,r,L,R,id<<1|1));
}
void solve(){
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n==1){
                int x,y;
                while(q--) cin>>x>>y,cout<<0<<' ';
                cout<<'\n';
                return;
        }
        for(int i=1;i<n;i++) v[i]=abs(a[i+1]-a[i]);
        build(1,n-1,1);
        int x,y;
        while(q--){
                cin>>x>>y;
                cout<<query(1,n-1,x,y-1,1)<<' ';
        }
        cout<<'\n';
}
signed main(){
        int t=1;
        cin>>t;
        while(t--) solve();
}
