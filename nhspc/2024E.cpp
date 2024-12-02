#include<bits/stdc++.h>
using namespace std;
struct hs{
    int p,l,r,id;
    hs(int P=0,int L=0,int R=0,int Id=0):p(P),l(L),r(R),id(Id){}
    bool operator < (hs o) const{
        if(r==o.r) return l<o.l;
        return r<o.r;
    }
} a[200500];
int ans[200500],ans2[200500];
int n;
vector<hs> qry;
set<int> lf,rg,df;
set<pair<int,int>> rk;
bool comp(hs a,hs b){
        if(a.p==0) return 1;
        return a.p<b.p;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].p;
    for(int i=1;i<=n;i++)cin>>a[i].l,df.insert(i);
    for(int i=1;i<=n;i++)cin>>a[i].r,a[i].id=i;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
            if(a[i].p==0) break;
            if(i!=1) {
                    a[i].l=max(a[i].l,a[i-1].l);
                    if(a[i].r<a[i-1].l){
                            cout<<-1<<'\n';
                            return 0;
                    }
            }
            if(a[i+1].p!=0) a[i].r=min(a[i].r,a[i+1].r);
    }
    for(int i=1;i<=n;i++){
            if(a[i].p==0){
                    qry.push_back(a[i]);
            }else{
                    rk.insert({a[i].p,i});
                    lf.insert(a[i].l);
                    rg.insert(a[i].r);
                    df.erase(a[i].p);
                    ans[a[i].id]=a[i].p;
            }
    }
    sort(qry.begin(),qry.end());
}
