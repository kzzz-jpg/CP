#include<bits/stdc++.h>
using namespace std;
int kui,tot,lazy[2000],L[2000],R[2000];
int pos[1000500],a[1000500];
int d[1050][1050];
int n,q,cnt;
void resort(int x){
        for(int i=1;i<=kui;i++) d[x][i]=a[L[x]+i-1];
        sort(d[x]+1,d[x]+1+kui);
}
void add(int l,int r,int v){
        if(pos[l]==pos[r]){
                for(int i=l;i<=r;i++) a[i]+=v;
                resort(pos[l]);
                return;
        }
        for(int i=l;i<=R[pos[l]];i++) a[i]+=v;
        for(int i=L[pos[r]];i<=r;i++) a[i]+=v;
        resort(pos[l]),resort(pos[r]);
        for(int i=pos[l]+1;i<=pos[r]-1;i++) lazy[i]+=v;
}
int qry(int l,int r,int v){
        if(pos[l]==pos[r]){
                int ret=0;
                for(int i=l;i<=r;i++) if(a[i]+lazy[pos[l]]>=v) ret++;
                return ret;
        }
        int ret=0;
        for(int i=l;i<=R[pos[l]];i++) if(a[i]+lazy[pos[l]]>=v) ret++;
        for(int i=L[pos[r]];i<=r;i++) if(a[i]+lazy[pos[r]]>=v) ret++;
        for(int k=pos[l]+1;k<=pos[r]-1;k++){
                int x=v-lazy[k];
                ret+=kui-(lower_bound(d[k]+1,d[k]+1+kui,x)-(d[k]+1));
        }
        return ret;
}
signed main(){
        cin>>n>>q;
        kui=sqrt(n);
        tot=n/kui;
        if(n%kui) tot++;
        for(int i=1;i<=tot;i++){
                L[i]=(i-1)*kui+1;
                R[i]=i*kui;
        }
        R[tot]=n;
        for(int i=1;i<=n;i++){
                cin>>a[i];
                pos[i]=(i-1)/kui+1;
        }
        for(int i=1;i<=tot;i++) resort(i);
        char op;
        int l,r,v;
        while(q--){
                cin>>op>>l>>r>>v;
                if(op=='M') add(l,r,v);
                else cout<<qry(l,r,v)<<'\n';
        }
}
