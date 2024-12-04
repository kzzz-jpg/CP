#include<bits/stdc++.h>
using namespace std;
int col[100500];
struct nd{
        int t,d;
        bool operator<(nd o)const{
                if(col[t]==1) return 1;
                return d>o.d;
        }
        nd(int tt=0,int dd=0):t(tt),d(dd){}
} v[100500];
int n,k,nw,ans;
bool comp(nd a,nd b){
        return a.d>b.d;
}
signed main(){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>v[i].t>>v[i].d;
        sort(v+1,v+1+n,comp);
        int i=1;
        priority_queue<nd> pq;
        for(;i<=k;i++) {
                pq.push(v[i]);
                ans+=v[i].d;
                if(col[v[i].t]++==0) ans+=2*nw+1,nw++;
        }
        for(;i<=n;i++){
                if(nw==k) break;
                if(col[v[i].t])break;
                if(2*nw+1+v[i].d>pq.top().d){
                        col[v[i].t]++;
                        ans-=pq.top().d;
                        ans+=v[i].d+2*nw+1;
                        nw++;
                        pq.pop();
                        pq.push(v[i]);
                }
        }
        cout<<ans<<'\n';
}
