#include<bits/stdc++.h>
using namespace std;
#define int long long
struct nd{
    int up,dw,l,r;
    int row,col;
};
nd dl[200500];
int ans[200500],row[200500],sz[200500];
int n,m,cnt=0;
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
int dancing(int deep){
    if(dl[0].r==0){
        for(int i=1;i<deep;i++) cout<<ans[i]<<' ';
        return 1;
    }
    int C=dl[0].r;
    for(int i=dl[0].r;i!=0;i=dl[i].r){
        if(sz[i]<sz[C]) C=i;
    }
    rm(C);
    for(int i=dl[C].dw;i!=C;i=dl[i].dw){
        ans[deep]=dl[i].row;
        for(int j=dl[i].r;j!=i;j=dl[j].r) rm(dl[j].col);
        if(dancing(deep+1)==1) return 1;
        for(int j=dl[i].r;j!=i;j=dl[j].r) rc(dl[j].col);
    }
    rc(C);
    return 0;
}
signed main(){
    cin>>n>>m;
    init();
    int t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>t;
            if(t==1) addnd(i,j);
        }
    }
    if(!dancing(1)){
        cout<<"No Solution!";
    }
    cout<<'\n';
    return 0;
}