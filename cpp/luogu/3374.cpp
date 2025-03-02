#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,a[500500],fw[500500];
void upd(int pos,int v){
    for(;pos<=n;pos+=pos&-pos){
        fw[pos]+=v;
    }
}
int qry(int pos){
    int ret=0;
    for(;pos;pos-=pos&-pos){
        ret+=fw[pos];
    }
    return ret;
}
int qry(int l,int r){
    return qry(r)-qry(l-1);
}
signed main(){
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        upd(i,a[i]);
    }
    int op,l,r;
    while(q--){
        scanf("%lld%lld%lld",&op,&l,&r);
        if(op==1){
            upd(l,r);
        }else{
            printf("%lld\n",qry(l,r));
        }
    }
}