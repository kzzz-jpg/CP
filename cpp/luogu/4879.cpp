#include<bits/stdc++.h>
#define int long long
using namespace std;
const int kui=sqrt(500000);
int n,q;
int a[500500],pos[500500],has[500500],cnt[2000],sum[2000],st[2000];
int qry(){
        int ret=0;
        for(int i=1;i<=kui+5;i++) ret+=sum[i];
        return ret;
}
void chg(int x,int v){
        a[x]-=v;
        sum[pos[x]]-=v;
}
void upd(int x,int v){
        sum[pos[x]]-=a[x];
        a[x]=v;
        sum[pos[x]]+=a[x];
        if(has[x]==0) has[x]=1,cnt[pos[x]]++;
}
void del(int x){
        int nw=0;
        int i=0;
        for(;i<=kui+5;i++) if(nw+cnt[i]>=x) break;else nw+=cnt[i];
        for(int k=st[i];pos[k]==i;k++){
                if(has[k]) nw++;
                if(nw==x){
                        has[k]=0;
                        cnt[pos[k]]--;
                        sum[pos[k]]-=a[k];
                        a[k]=0;
                        return;
                }
        }
}
signed main(){
        ios_base::sync_with_stdio(0),cin.tie(0);
        cin>>n>>q;
        st[1]=1;
        pos[1]=1;
        for(int i=1;i<=500100;i++) {
                pos[i]=i/kui+1;
                if(i%kui==0) st[pos[i]]=i;
        }
        for(int i=1;i<=n;i++) {
                cin>>a[i],has[i]=1,sum[pos[i]]+=a[i],cnt[pos[i]]++;
        }
        int x,y;
        char op;
        while(q--){
                cin>>op;
                if(op=='Q') cout<<qry()<<'\n';
                else if(op=='C'){
                        cin>>x>>y;
                        chg(x,y);
                }else if(op=='I'){
                        cin>>x>>y;
                        upd(x,y);
                }else{
                        cin>>x;
                        del(x);
                }
        }
}
