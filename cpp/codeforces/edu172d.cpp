#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nd{
    int l,r,id;
    bool operator < (nd o) const{
        if(l==o.l) return r>o.r;
        return l<o.l;
    }
    void rev(){
            swap(l,r);
            l=1e9-l+1;
            r=1e9-r+1;
    }
};
struct node{
        int l,r,v;
        node *ls,*rs;
        node(int L,int R,int V=0,node *lss=nullptr,node *rss=nullptr):l(L),r(R),v(V),ls(lss),rs(rss){}
};
int query(node *root,int l,int r){
        if(root->l>r||root->r<l) return 0;
        if(root->l<=l&&root->r>=r) return root->v;
        int ret=0;
        if(root->ls!=nullptr) ret=max(ret,query(root->ls,l,r));
        if(root->rs!=nullptr) ret=max(ret,query(root->rs,l,r));
        return ret;
}
void update(node *root,int pos,int val){
        if(root->l==root->r){
                root->v=max(root->v,val);
                return;
        }
        int mid=(root->l+root->r)>>1;
        if(pos>mid){
                if(root->rs==nullptr) root->rs=new node(mid+1,root->r);
                update(root->rs,pos,val);
        }
        if(pos<=mid){
                if(root->ls==nullptr) root->ls=new node(root->l,mid);
                update(root->ls,pos,val);
        }
        if(root->ls) root->v=max(root->v,root->ls->v);
        if(root->rs) root->v=max(root->v,root->rs->v);
}
void solve(){
    int n;
    cin>>n;
    vector<nd> v(n);
    vector<int> ans(n);
    map<pair<int,int>,int> mp;
    for(int i=0;i<n;i++) cin>>v[i].l>>v[i].r,v[i].id=i;
    sort(v.begin(),v.end());
    node *root=new node(1,1e9);
    for(int i=0;i<n;i++) mp[{v[i].l,v[i].r}]++;
    for(int i=0;i<n;i++){
            int nw=query(root,v[i].r,1e9);
            if(nw!=0&&mp[{v[i].l,v[i].r}]<2) ans[v[i].id]+=v[i].l-nw;
            update(root,v[i].r,v[i].l);
    }
    for(int i=0;i<n;i++) v[i].rev();
    map<pair<int,int>,int> mp2;
    sort(v.begin(),v.end());
    root = new node(1,1e9);
    for(int i=0;i<n;i++) mp2[{v[i].l,v[i].r}]++;
    for(int i=0;i<n;i++){
            int nw=query(root,v[i].r,1e9);
            if(nw!=0&&mp2[{v[i].l,v[i].r}]<2) ans[v[i].id]+=v[i].l-nw;
            update(root,v[i].r,v[i].l);
    }
    for(int i=0;i<n;i++) cout<<max(0LL,ans[i])<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}
