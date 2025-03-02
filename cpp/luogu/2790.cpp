#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,k,a[100500],pos[100500],kui,ans[200500],nw,mp[200500];
struct nd{
    int l,r,id;
    bool operator<(nd o)const{
        if(pos[l]==pos[o.l]) {
            if(pos[l]&1) return r<o.r;
            else return r>o.r;
        }
        return pos[l]<pos[o.l];
    }
} qr[100500];
void add(int x){
    nw-=mp[a[x]]*mp[a[x]];
    mp[a[x]]++;
    nw+=mp[a[x]]*mp[a[x]];
}
void del(int x){
    nw-=mp[a[x]]*mp[a[x]];
    mp[a[x]]--;
    nw+=mp[a[x]]*mp[a[x]];
}
signed main(){
    scanf("%lld%lld%lld",&n,&q,&k);
    kui=sqrt(n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),pos[i]=(i-1)/kui+1;
    for(int i=1;i<=q;i++) {
        scanf("%lld%lld",&qr[i].l,&qr[i].r);
        qr[i].id=i;
    }
    sort(qr+1,qr+1+q);
    for(int i=1,l=1,r=0;i<=q;i++){
        while(r>qr[i].r) del(r--);
        while(r<qr[i].r) add(++r);
        while(l>qr[i].l) add(--l);
        while(l<qr[i].l) del(l++);
        ans[qr[i].id]=nw;
    }
    for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
}