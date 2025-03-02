#include<stdio.h>
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
#define max(a,b) (a>b?a:b)
int n,q,a[100500],tr[400500];
void build(int l,int r,int id){
    if(l==r){
        tr[id]=a[l];
        return;
    }
    int mid=l+r>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    tr[id]=max(tr[id<<1],tr[id<<1|1]);
}
int query(int l,int r,int L,int R,int id){
    if(l>R||r<L) return 0;
    if(L<=l&&r<=R) return tr[id];
    int mid=l+r>>1;
    return max(query(l,mid,L,R,id<<1),query(mid+1,r,L,R,id<<1|1));
}
signed main(){
    n=read(),q=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build(1,n,1);
    int l,r;
    while(q--){
        l=read(),r=read();
        printf("%d\n",query(1,n,l,r,1));
    }
}