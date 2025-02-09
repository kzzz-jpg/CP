#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
using namespace std;
#define int long long
struct DLX{
    int l,r,up,dw;
    int row,col;
} dlx[200000];
int row[300],sz[200000];
int n,m,cnt,ans;
void init(){
    for(int i=0;i<=m;i++){
        dlx[i].l=i-1;
        dlx[i].r=i+1;
        dlx[i].up=dlx[i].dw=i;
    }
    dlx[0].l=m;
    dlx[m].r=0;
    cnt=m;
}
void addnd(int r,int c){
    dlx[++cnt].up=dlx[c].up;
    dlx[cnt].dw=c;
    dlx[dlx[c].up].dw=cnt;
    dlx[c].up=cnt;
    dlx[cnt].col=c;
    dlx[cnt].row=r;
    sz[c]++;
    if(!row[r]){
        row[r]=cnt;dlx[cnt].l=dlx[cnt].r=cnt;
    }else{
        dlx[cnt].l=dlx[row[r]].l;
        dlx[cnt].r=row[r];
        dlx[dlx[row[r]].l].r=cnt;
        dlx[row[r]].l=cnt;
    }
}
void del(int c){
    dlx[dlx[c].l].r=dlx[c].r;
    dlx[dlx[c].r].l=dlx[c].l;
    for(int i=dlx[c].dw;i!=c;i=dlx[i].dw){
        for(int j=dlx[i].r;i!=j;j=dlx[j].r){
            dlx[dlx[j].up].dw=dlx[j].dw;
            dlx[dlx[j].dw].up=dlx[j].up;
            sz[dlx[j].col]--;
        }
    }
}
void res(int c){
    for(int i=dlx[c].dw;i!=c;i=dlx[i].dw){
        for(int j=dlx[i].r;j!=i;j=dlx[j].r){
            dlx[dlx[j].up].dw=j;
            dlx[dlx[j].dw].up=j;
            sz[dlx[j].col]++;
        }
    }
    dlx[dlx[c].l].r=c;
    dlx[dlx[c].r].l=c;
}
void dance(){
    if(dlx[0].r==0){
        ans++;
        return;
    }
    int C=dlx[0].r;
    for(int i=dlx[0].r;i!=0;i++) if(sz[i]<sz[C]) C=i;
    del(C);
    for(int i=dlx[C].dw;i!=C;i=dlx[i].dw){
        for(int j=dlx[i].r;j!=i;j=dlx[j].r) del(dlx[j].col);
        dance();
        for(int j=dlx[i].r;j!=i;j=dlx[j].r) res(dlx[j].col);
    }
    res(C);
}
signed main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++);
    }
}
