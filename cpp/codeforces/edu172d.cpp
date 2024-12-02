#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nd{
    int l,r,id;
    bool operator < (nd o) const{
        if(l==o.l) return r>o.r;
        return l<o.l;
    }
};
bool comp(nd a,nd b){
    if(a.r==b.r) return a.l<b.l;
    return a.r>b.r;
}
void solve(){
    int n;
    cin>>n;
    vector<nd> v(n);
    vector<int> ans(n);
    for(int i=0;i<n;i++) cin>>v[i].l>>v[i].r,v[i].id=i;
    sort(v.begin(),v.end());
    set<int> r;
    set<int,greater<int>> l;
    r.insert(v[0].r);
    for(int i=1;i<n;i++){
        int nwr=0;
        auto it=r.lower_bound(v[i].r);
        if(it==r.end()){
            r.insert(v[i].r);
            ans[v[i].id]=-1;
            continue;
        }
        if((*it==v[i].r)&&next(it)==r.end()) nwr=0;
        else{
            nwr=*it-v[i].r;
        }
        ans[v[i].id]=nwr;
        r.insert(v[i].r);
    }
    
    sort(v.begin(),v.end(),comp);
    l.insert(v[0].l);
    for(int i=1;i<n;i++){
        if(v[i].l==v[i-1].l&&v[i].r==v[i-1].r) ans[v[i-1].id]=ans[v[i].id]=-1;
        if(ans[v[i].id]==-1) continue;
        int nwl=0;
        auto it=l.lower_bound(v[i].l);
        if(it==l.end()){
            l.insert(v[i].l);
            ans[v[i].id]=-1;
            continue;
        }
        //cerr<<*it<<' '<<v[i].id<<'\n';
        nwl=v[i].l-*it;
        ans[v[i].id]+=nwl;
        l.insert(v[i].l);
    }
    for(int i=0;i<n;i++) cout<<max(0LL,ans[i])<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}