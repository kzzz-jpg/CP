#include<bits/stdc++.h>
using namespace std;
random_device rd;
unsigned int seed=rd();
mt19937 rg(rd());
struct Treap{
    Treap *l=nullptr,*r=nullptr;
    int v,size,pri,sum,tsz,mx;
    Treap(int x,int sz): sum(x*sz),size(sz),pri(rg()),v(x),mx(x) {};
    void pull();
};
void Treap::pull(){
    tsz=size;
    if(l!=nullptr) {
        tsz+=l->tsz;
        sum+=l->sum;
        mx=max(mx,l->mx);
    }
    if(r!=nullptr) {
        tsz+=r->tsz;
        sum+=r->sum;
        mx=max(mx,r->mx);
    }
    return;
}
int size(Treap *a){
    if(a==nullptr) return 0;
    return a->tsz;
}
Treap *merge(Treap *a,Treap *b){
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    if(a->pri<b->pri){
        a->r=merge(a->r,b);
        a->pull();
        return a;
    }else{
        b->l=merge(a,b->l);
        b->pull();
        return b;
    }
}
void split_by_val(Treap *p,Treap *&a,Treap *&b,int val){
    if(p==nullptr){
        a=b=nullptr;
        return ;
    }
    if(p->v<val){
        a=p;
        split_by_val(p->r,a->r,b,val);
        a->pull();
    }else{
        b=p;
        split_by_val(p->l,a,b->l,val);
        b->pull();
    }
}
void split(Treap *p,Treap *&a,Treap *&b,int k){
    if(p==nullptr) {
        a=b=nullptr;
        return;
    }
    if(size(p->l)<k){
        a=p;
        split(p->r,a->r,b,k-size(p->l)-p->size);
        a->pull();
    }else{
        b=p;
        split(p->l,a,b->l,k);
        b->pull();
    }
}
void erase(Treap *&root,int x){
    Treap *a,*b,*c,*temp;
    split_by_val(root,a,b,x);
    split_by_val(b,b,c,x+1);
    split(b,temp,b,1);
    delete temp;
    root=merge(merge(a,b),c);
}
void insrt(Treap *&root,int k,int sz){
    Treap *l,*r,*c;
    split_by_val(root ,l,r,k);
    split_by_val(r,r,c,k+1);
    if(size(r)==0) root=merge(merge(l,new Treap(k,sz)),c);
    else r->size+=sz,root=merge(merge(l,r),c);
    return;
}
int a[200500],b[200500];
int n,q;
void query1(Treap *&root,int x,int y){
    Treap *l,*r,*c;
    split_by_val(root,l,r,a[x]);
    split_by_val(l,l,c,a[x]+1);
    r->size-=b[x];
    root=merge(merge(l,r),c);
    a[x]=y;
    insrt(root,a[x],b[x]); 
}
void query2(Treap *&root,int x,int y){
    Treap *l,*r,*c;
    split_by_val(root,l,r,a[x]);
    split_by_val(r,r,c,a[x]+1);
    r->size-=b[x];
    b[x]=y;
    r->size+=b[x];
    root=merge(merge(l,r),c);
}
int query3(Treap *&root,int x){
    Treap *l,*r;
    split(root,l,r,size(root)-x);
    x-=size(r);
    return r->sum+l->mx*x;
}
signed main(){
    int x,y,op;
    Treap *root=nullptr;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        insrt(root,a[i],b[i]);
    }
    cin>>q;
    while(q--){
        cin>>op;
        if(op==1){
            cerr<<1<<'\n';
            cin>>x>>y;
            query1(root,x,y);
        }else if(op==2){
            cin>>x>>y;
            cerr<<2<<'\n';
            query2(root,x,y);
        }else{
            cin>>x;
            cerr<<3<<'\n';
            cout<<query3(root,x);
        }
    }
}