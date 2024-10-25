#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct node{
    int v,d;
    node(int V,int D):v(V),d(D){}
    bool operator <(node o) const{
        return v*(d+1)*(d+1)-v*d*d>o.v*(o.d+1)*(o.d+1)-o.v*o.d*o.d;
    }
};
priority_queue<node> pq;
int ans=0;
int a[200500];
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    pq.push(node(a[1],0));
    for(int i=2;i<=n;i++){
        auto tp=pq.top();pq.pop();
        ans=ans-tp.v*tp.d*tp.d;
        tp.d++;
        ans=ans+tp.v*tp.d*tp.d+a[i];
        pq.push(tp);pq.push(node(a[i],1));
    }
    cout<<ans<<'\n';
}