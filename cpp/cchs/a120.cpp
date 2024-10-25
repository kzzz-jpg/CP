#include<bits/stdc++.h>
using namespace std;
#define IT set<odt>::iterator
struct odt{
    int l,r;
    mutable int v;
    bool operator<(odt o) const{
        return l<o.l;
    }
    odt(int L,int R=-1,int V=0):l(L),r(R),v(V){}
};
set<odt> s;
IT split(int pos){
    IT it=s.lower_bound(odt(pos));
    if(it!=s.end()&&it->l==pos) return it;
    it--;
    int l=it->l,r=it->r,v=it->v;
    s.erase(it);
    s.insert(odt(l,pos-1,v));
    return s.insert(odt(pos,r,v)).first;
}
void tp(int l,int r){
    IT itr=split(r+1),itl=split(l);
    s.erase(itl,itr);
    s.insert(odt(l,r,1));
}
int n,m,L,R,ans;
signed main(){
    cin>>n>>m;
    s.insert(odt(0,m+1,0));
    while(n--){
        cin>>L>>R;
        L++;
        tp(L,R);
    }
    for(auto x:s){
        if(x.v){
            ans+=x.r-x.l+1;
        }
    }
    cout<<ans<<'\n';
}