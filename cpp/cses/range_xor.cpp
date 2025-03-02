#include<bits/stdc++.h>
#include <ios>
using namespace std;
int n,q,pos[200500],a[200500],nw,ans[200500],kui;
struct query{
    int l,r,id;
    bool operator<(query o)const{
        if(pos[l]==pos[o.l]) {
            if(pos[l]&1)
                return r<o.r;
            else
                return r>o.r;
        }
        return pos[l]<pos[o.l];
    }
} qr[200500];
signed main(){
    scanf("%d%d",&n,&q);
    kui=sqrt(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[i]=(i-1)/kui+1;
    }
    for(int i=1;i<=q;i++){
        cin>>qr[i].l>>qr[i].r;
        qr[i].id=i;
    }
    sort(qr+1,qr+1+q);
    for(int i=1,l=1,r=0;i<=q;i++){
        while(l>qr[i].l) nw^=a[--l];
        while(l<qr[i].l) nw^=a[l++];
        while(r<qr[i].r) nw^=a[++r];
        while(r>qr[i].r) nw^=a[r--];
        ans[qr[i].id]=nw;
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
}