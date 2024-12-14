#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
#define int long long
struct nd{
    int up,dw,l,r;
    int row,col;
};
nd dl[6000500];
int ans,row[2000500],sz[2000500];
int n,m,cnt=0;
int h,w,q;
void init(){
    for(int i=0;i<=m;i++){
        dl[i].l=i-1;
        dl[i].r=i+1;
        dl[i].up=i;
        dl[i].dw=i;
        sz[i]=0;
    }
    dl[0].l=m;
    dl[m].r=0;
    cnt=m;
}
void rm(int c){
    dl[dl[c].l].r=dl[c].r;
    dl[dl[c].r].l=dl[c].l;
    for(int i=dl[c].dw;i!=c;i=dl[i].dw){
        for(int j=dl[i].r;j!=i;j=dl[j].r){
            dl[dl[j].up].dw=dl[j].dw;
            dl[dl[j].dw].up=dl[j].up;
            sz[dl[j].col]--;
        }
    }
}
void rc(int c){
    for(int i=dl[c].dw;i!=c;i=dl[i].dw){
        for(int j=dl[i].r;j!=i;j=dl[j].r){
            dl[dl[j].up].dw=j;
            dl[dl[j].dw].up=j;
            sz[dl[j].col]++;
        }
    }
    dl[dl[c].l].r=c;
    dl[dl[c].r].l=c;
}
void addnd(int r,int c){
    dl[++cnt].up=dl[c].up;
    dl[cnt].dw=c;
    dl[c].up=cnt;
    dl[dl[cnt].up].dw=cnt;
    dl[cnt].col=c;
    dl[cnt].row=r;
    sz[c]++;
    if(!row[r]){
        dl[cnt].r=cnt;
        dl[cnt].l=cnt;
        row[r]=cnt;
    }else{
        dl[cnt].r=row[r];
        dl[cnt].l=dl[row[r]].l;
        dl[row[r]].l=cnt;
        dl[dl[cnt].l].r=cnt;
    }
}
void dancing(int deep){
        ans=max(ans,deep-1);
        if(dl[0].r==0) return;
    int C=dl[0].r;
    for(int c=C;c!=0;c=dl[c].r){
            if(sz[c]>sz[C]) C=c;
    }
    rm(C);
    for(int i=dl[C].dw;i!=C;i=dl[i].dw){
        for(int j=dl[i].r;j!=i;j=dl[j].r) rm(dl[j].col);
        dancing(deep+1);
        for(int j=dl[i].r;j!=i;j=dl[j].r) rc(dl[j].col);
    }
    rc(C);
}
signed main(){
        ios_base::sync_with_stdio(0),cin.tie(0);
        cin>>h>>w>>q;
        m=h+q+w;
        init();
        int a,b,c,d;
        int t=1;
        for(int i=1;i<=q;i++){
                cin>>a>>b>>c>>d;
                for(int ii=a;ii<=c;ii++){
                        for(int j=b;j<=d;j++){
                                addnd(t,ii);
                                addnd(t,j+h);
                                addnd(t,h+w+i);
                                t++;
                        }
                }
        }
        dancing(1);
        cout<<ans<<'\n';
        return 0;
}
