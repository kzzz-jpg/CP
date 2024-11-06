#include<bits/stdc++.h>
#include<random>
using namespace std;
random_device rd;
unsigned int seed=rd();
mt19937 rg(rd());
struct Treap{
    Treap *l=nullptr,*r=nullptr;
    int v,size,pri;
    Treap(int x): size(1),pri(rg()),v(x) {};
    void pull();
    void push();
};
void Treap::pull(){
    size=1;
    if(l!=nullptr) {
        size+=l->size;
    }
    if(r!=nullptr) {
        size+=r->size;
    }
    return;
}
void Treap::push(){
    if(l!=nullptr){
        l->v=v;
        l->push();
    }
    if(r!=nullptr){
        r->v=v;
        r->push();
    }
}
int size(Treap *a){
    if(a==nullptr) return 0;
    return a->size;
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
        split(p->r,a->r,b,k-size(p->l)-1);
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
void *insrt(Treap *&root,int k){
    Treap *l,*r;
    split_by_val(root ,l,r,k);
    root=merge(merge(l,new Treap(k)),r);
}
void query(Treap *&root);
