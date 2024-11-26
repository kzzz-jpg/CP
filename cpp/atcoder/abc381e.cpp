#include<bits/stdc++.h>
using namespace std;
int n,q;
char v[100500];
int p1[100500],p2[100500];
int pos[100500],kui,fk[1000];
int ans[100500];
struct Q{
        int l,r,id;
        bool operator < (Q o)const{
                if(pos[l]==pos[o.l]) return r<o.r;
                return l<o.l;
        }
} qry[100500];
signed main(){
        cin>>n>>q;
        kui=sqrt(n);
        for(int i=1;i<=n;i++) cin>>v[i],p1[i]=p1[i-1]+(v[i]=='1'),p2[i]=p2[i-1]+(v[i]=='2'),pos[i]=i/kui+1;
        for(int i=1;i<=q;i++) cin>>qry[i].l>>qry[i].r,qry[i].id=i;
        sort(qry+1,qry+1+q);
        for(int i=1,l=1,r=0;i<=q;i++){
                while(r<qry[i].r) add(++r,i);
                while(r>qry[i].r) del(r--,i);
                while(l>qry[i].l) add(--l,i);
                while(l<qry[i].l) del(l++,i);
        }
}
