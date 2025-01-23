#include<bits/stdc++.h>
using namespace std;
int n,q,x,y,xx,yy,op;
int fw1[200500],fw2[200500];
void upd1(int x,int v){
    for(;x<=n;x+=x&-x) fw1[x]+=v;
}
void upd2(int x,int v){
    for(;x<=n;x+=x&-x) fw2[x]+=v;
}
int qry1(int x){
    int ret=0;
    for(;x;x-=x&-x) ret+=fw1[x];
    return ret;
}
int qry2(int x){
    int ret=0;
    for(;x;x-=x&-x) ret+=fw2[x];
    return ret;
}
int qry1(int l,int r){
    return qry1(r)-qry1(l-1);
}
int qry2(int l,int r){
    return qry2(r)-qry2(l-1);
}
void solve(){
    cin>>n>>q;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>x>>y;
            upd1(x,1);
            upd2(y,1);
        }
        if(op==2){
            cin>>x>>y;
            upd1(x,-1);
            upd2(y,-1);
        }
        if(op==3){
            cin>>x>>y>>xx>>yy;
            if(qry1(x,xx)==(xx-x+1)||qry2(y,yy)==(yy-y+1)) cout<<"yes\n";
            else cout<<"no\n";
        }
    }
}
signed main(){
    int t=1;
   // cin>>t;
    while(t--) solve();
}